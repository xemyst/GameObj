#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <pthread.h>
#include <math.h>
#include "timer.h"
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/timer.h"
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/SimpleSerial.h"
//grSim library
#include "/home/robotica/Documentos/futebol/ssl-vision-master/build/grSim_Packet.pb.h"
#include <QThread>
#include <QtNetwork>
//For UDP Multicast connection
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/net/robocup_ssl_client.h"
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/net/referee_client.h"
//Protobuff libraries
#include "referee.pb.h"
#include "messages_robocup_ssl_detection.pb.h"
#include "messages_robocup_ssl_geometry.pb.h"
#include "messages_robocup_ssl_wrapper.pb.h"
//Funcao de movimentacao do robo
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/Move_Robot.h"
//Funcao de virar do robo
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/Turn_Robot.h"
//Gera comandos para o Simulador grSim
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/grSim_Command.h"
//Aplica A* para achar melhor caminho
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/a_star.h"
//Comunicacao Serial PC arduino
#include "TimeoutSerial.h"
//Inclui os objetos e suas funçoes
//#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/GameObj.cpp"
//#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/Bola.cpp"
//include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/Defensor.cpp"
//#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/fieldPoint.cpp"
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/Robo.cpp"
//include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/Atacante.cpp"

//#define Meu_Robo B_Robots
//#define Adversario Y_Robots
#define Meu_Robo Y_Robots
#define Adversario B_Robots
#define goleiro 5
#define VMAX 15

using namespace std;
using namespace boost;

volatile sig_atomic_t print_flag = false;
void handle_alarm( int sig ) 
{
	print_flag = true;
}

//cria dois tipos de structs para armazenar x,y e theta
struct complexa
{
	float x,y,theta;
};

struct simples
{
	float x,y;
};

struct params
{
	int R, L, speed_z, speed_x, id;
	bool verifica;
};

//cria as structs que vão armazenar os dados de robôs e bola
struct complexa Y_Robots[12];
struct complexa B_Robots[12];
struct simples bola;
struct params pwm_motor;
struct params move_closer_robot;
struct params move_other_robot;

//Armazenamento de posiçoes, podem ser acessados por qual robo.



//Robo

Robo Aliado[6];
Robo Inimigo[6];

//Bola bola1;
//Enemigo Robo_B[12];
//Robo Robo_Y[12];

int ciclo = 0;//variável para controle para coletar os frames dos 4 quadrantes

void* visao(void*)
{
	//cria socket UDP
	RoboCupSSLClient client;
	client.open(true);
	SSL_WrapperPacket packet;
	
		

        while(true)
        {
		if (client.receive(packet))
		{
			if (packet.has_detection())
			{
				SSL_DetectionFrame detection = packet.detection();

				int balls_n = detection.balls_size();
				int robots_blue_n =  detection.robots_blue_size();
				int robots_yellow_n =  detection.robots_yellow_size();

				//ball info
				for (int i = 0; i < balls_n; i++)
				{
					SSL_DetectionBall ball = detection.balls(i);

					if (ball.has_x() && ball.has_y())
					{
						//bola1.setX(ball.x());
						//bola1.setY(ball.Y());
						bola.x = ball.x();
						bola.y = ball.y();
						Bola.setX(ball.x());
						Bola.setY(ball.y());				
					}
				}

				//Blue robot info:
				for (int i = 0; i < robots_blue_n; i++)
				{
					SSL_DetectionRobot robot = detection.robots_blue(i);

					if (robot.has_robot_id())
					{
						Azul[robot.robot_id()].setX(robot.x());
						Azul[robot.robot_id()].setY(robot.y());
						Azul[robot.robot_id()].setTheta(robot.orientation());
						B_Robots[robot.robot_id()].x = robot.x();
						B_Robots[robot.robot_id()].y = robot.y();
						B_Robots[robot.robot_id()].theta = robot.orientation();
						//Robo_B[robot.robot_id()].setX(robot.x());
						//Robo_B[robot.robot_id()].setY(robot.y());
						//Robo_B[robot.robot_id()].setTheta(robot.orientation());
					}
				}

				//Yellow robot info:
				for (int i = 0; i < robots_yellow_n; i++)
				{
					SSL_DetectionRobot robot = detection.robots_yellow(i);

					if (robot.has_robot_id())
					{
						Amarelo[robot.robot_id()].setX(robot.x());
						Amarelo[robot.robot_id()].setY(robot.y());
						Amarelo[robot.robot_id()].setTheta(robot.orientation());
						Y_Robots[robot.robot_id()].x = robot.x();
						Y_Robots[robot.robot_id()].y = robot.y();
						Y_Robots[robot.robot_id()].theta = robot.orientation();
						//Robo_Y[robot.robot_id()].setX(robot.x());
						//Robo_Y[robot.robot_id()].setY(robot.y());
						//Robo_Y[robot.robot_id()].setTheta(robot.orientation());
					}
				}
			}
		}

		ciclo = ciclo +1; //incrementa variável auxiliar
		usleep(1000);
	}
}

void* juiz(void*)
{
	//abre socket UDP multicast
	RefereeClient referee_client;
	referee_client.open(true);
	SSL_Referee referee;

	while(true)
	{
		if (referee_client.receive(referee))
		{
		    //printf("-----Received Referee_Box Packet---------------------------------------------\n");
		    //see if the packet contains a robot detection frame:
		    if (referee.has_packet_timestamp())
		    {
			//printf("\n\nTS = %lu , stage = %u \n ",referee.packet_timestamp(),referee.stage());
			//printf("stage_time_left = %u , command= = %u \n\n ",referee.stage_time_left(),referee.command());
			//printf("yscore= = %u , bscore= = %u \n\n ",referee.yellow().score(),referee.blue().score());
		    }
		}
		usleep(10000);
	}
}

void* controle(void*)
{
	while(1)
	{
		if (ciclo >= 4)
		{
			ciclo = 0;//zera variável auxiliar para que a cada 4 frames, um de cada quadrante, haja uma leitura total do campo
			//printf("\nBall POS=<%9.2f,%9.2f\n", bola.x,bola.y);

			/*for(int i = 0; i < 12; i++)
			{
				//printf("Robo_Amarelo (%i) - POS=<%9.2f,%9.2f>, ANGLE=%6.3f\n",i,Y_Robots[i].x,Y_Robots[i].y,Y_Robots[i].theta);
			}
			for(int i = 0; i < 12; i++)
			{
				//printf("Robo_Azul (%i) - POS=<%9.2f,%9.2f>, ANGLE=%6.3f\n",i,B_Robots[i].x,B_Robots[i].y,B_Robots[i].theta);
			}*/


			float Dist1 = 100000;
			int Closer_robot;
			int contagem = 0;

			//identifica qual robo esta mais perto da bola
			for(int i = 0; i < 12; i++)
			{
				if( (Amarelo[i].getX() != 0 && Amarelo[i].getY() != 0)  )
				{
					int Dist2 = sqrt( ((Bola.getX() - Amarelo[i].getX())*(Bola.getX() - Amarelo[i].getX())) + ((Bola.getY()-Amarelo[i].getY())*(Bola.getY()-Amarelo[i].getY() )) );

					if (Dist2 < Dist1)
					{
						Dist1 = Dist2;
						Closer_robot = i;
					}
					contagem++;
				}
			}

			//printf("\nHá %i Robos em campo\n", contagem);
			printf("\nRobo Mais Proximo da Bola = Robo ID (%i)\n", Closer_robot);

			for (int i = 0; i < 12; i++)
			{
				if( (Amarelo[i].getX() != 0 && Amarelo[i].getY() != 0) || (Bola.getX() != 0 && Bola.getY() != 0))
				{
					if (i == Closer_robot)
					{
						Aliado[Closer_robot].Menor_caminho_Update(Aliado[Closer_robot].aEstrela(Amarelo[Closer_robot].getX(),Amarelo[Closer_robot].getY(), Amarelo[Closer_robot].getTheta(), Bola.getX(),Bola.getY() ) );
						move_closer_robot = MoverPara(Closer_robot,Aliado[Closer_robot].getMenor_caminhoX(),Aliado[Closer_robot].getMenor_caminhoY(),Amarelo[Closer_robot].getTheta(),Amarelo[Closer_robot].getX(),Amarelo[Closer_robot].getY(),Bola.getX(),Bola.getY(), VMAX);
					}else if (i != goleiro)
					{
						struct simples Menor_caminho = astar(Meu_Robo[i].x,Meu_Robo[i].y, Meu_Robo[i].theta, 1000, i*360, Adversario);
						struct params move_other_robot = MoverPara(i, Menor_caminho.x,Menor_caminho.y,Meu_Robo[i].theta,Meu_Robo[i].x,Meu_Robo[i].y,1000,i*360, VMAX);
						if (move_other_robot.verifica == 1)
						{
							VirarPara(i, bola.x, bola.y, Meu_Robo[i].theta, Meu_Robo[i].x, Meu_Robo[i].y, VMAX, pwm_motor.speed_x, pwm_motor.speed_z);
						}
					}
				}
			}
		}
		usleep(7500);
	 }
}

void* comunica(void*)
{
	signal( SIGALRM, handle_alarm ); // Install handler first,
	ualarm( 100000,0 ); // before scheduling it to be called

	string msg = "";

	while(true)
	{

		int vr_closer = move_closer_robot.L;
		int vl_closer = move_closer_robot.R;

		int vr_other = move_other_robot.L;
		int vl_other = move_other_robot.R;

		if(move_closer_robot.id == 1)
		{
			//id=1
			vr_closer = (9 * vr_closer + 65*30) / 30;
			vl_closer = (9 * vl_closer + 75*30) / 30;

			//id=5 ou 3
			vr_other = (9 * vr_other + 85*30) / 30;
			vl_other = (9 * vl_other + 95*30) / 30;
		}

		if(move_closer_robot.id == 3 || move_closer_robot.id == 5)
		{
			//id=5 ou 3
			vr_closer = (9 * vr_closer + 85*30) / 30;
			vl_closer = (9 * vl_closer + 95*30) / 30;

			//id=1
			vr_other = (9 * vr_other + 65*30) / 30;
			vl_other = (9 * vl_other + 75*30) / 30;
		}

		msg = "";
		msg += char(vr_closer);
		msg += char(vl_closer);
		msg += char(vr_other);
		msg += char(vl_other);

		if ( print_flag )
		{
			try
			{
				TimeoutSerial serial("/dev/ttyACM1",9600);
				serial.writeString(msg);
			}

			catch(boost::system::system_error& e)
			{
				cout<<"Error: "<<e.what()<<endl;
			}

			//printf("\nenviando comando: %s\n, vr_closer = %i vl_closer = %i vr_other %i vl_other = %i ", msg.c_str(), vr_closer,vl_closer, vr_other, vl_other);
			printf("\nenviando comando: %s\n", msg.c_str());
			print_flag = false;
			ualarm( 100000,0 );
		}
	}
}

int main()
{
	pwm_motor.speed_z = 0;
	pwm_motor.speed_x = 0;

	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;

	pthread_create(&t1, NULL, &juiz, NULL);
	pthread_create(&t2, NULL, &visao, NULL);
	pthread_create(&t3, NULL, &controle, NULL);
	pthread_create(&t4, NULL, &comunica, NULL);

	while(1)
	{
	//	printf("hello world \n");	
    	//	GameObj obj[2];
    	//	obj[0] = Bola();
    	//	obj[0].setX(20);
    	//	obj[0].setY(40);
    	//	Robo j;
    	//	j.setX(80);
	// 	j.setY(100);
    	//	cout << j.objDistance(obj[0]) << endl;
		usleep(1000);
	}
	return 0;
}
