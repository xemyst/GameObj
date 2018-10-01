#include <iostream>
#include <stdio.h>
#include <math.h>
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/PID.h"

//Gera comandos para o Simulador grSim
#include "/home/robotica/Documentos/futebol/ssl-vision-master/src/shared/util/grSim_Command.h"

struct params
{
	int R, L, speed_z, speed_x, id;
	bool verifica;
};


struct params MoverPara(int indice, float x, float y, float rRotation, float rX, float rY,float bx,float by, int VELOCIDADEMAXIMA)
{	
	PID pid_motor_direito;
	PID pid_motor_esquerdo;

	// coeficiente proporcional (Kp), coeficiente integral (Ki), coeficiente derivativo(Kd)
	pid_motor_direito.Init(0.04, 0.0, 0.0);
	pid_motor_esquerdo.Init(-0.04, 0.0, 0.0);

	//variáveis de Set Point (SP), e Control Variable (CV)
	double SP = 0.0, CV_motor_direito = 0.0, CV_motor_esquerdo = 0.0;

	struct params movimento;
	movimento.speed_z = 0;
	movimento.speed_x = 0;
	movimento.id = indice;

	int PID_value;
        // Declara variáveis.
        float k, Theta, Angulo, Dist, vr, vl, ModTheta;
	int vl1,vr1;
        // Calcula a distância entre o robo e o ponto desejado.
        Dist = sqrt( ((bx-rX)*(bx-rX)) + ((by-rY)*(by-rY)) );
        //printf("\nRobo <%f, %f>, Bola <%f, %f> Distancia do robo ate a bola = %f\n",rX,rY,bx,by,Dist);

        // Calcula quantos graus o robô deve girar para
        // ficar em direção ao ponto desejado.
        Angulo = (180/M_PI)*atan2(y-rY, x-rX);
        Theta = Angulo - rRotation*(180/M_PI);
        //printf("Dist %.3f rRotation %.3f ang %.3f theta %.3f PI = %f\n",Dist,rRotation,Angulo,Theta,M_PI);

        // Ajusta o ângulo.
        while (Theta > 180) Theta -= 360;
        while (Theta < -180) Theta += 360;
        // ModTheta = |theta|.
        ModTheta = fabs(Theta);

	//Determina a velocidade de rotação
	// de acordo com o módulo do ângulo
	// que o robô precisa girar.
	// OBS: Esses valores podem ser alterados para
	// alterar a velocidade de rotação
	// do robô enquanto ele vai de encontro ao ponto (x,y).

	CV_motor_direito = pid_motor_direito.UpdateOutput( SP , Theta, VELOCIDADEMAXIMA);
	CV_motor_esquerdo = pid_motor_esquerdo.UpdateOutput(SP , Theta, VELOCIDADEMAXIMA);

	//printf("\nThetaAQUI %.3f \n ",Theta);

	//PID_value = Calcula_PID(Dist, PID_value.erro_anterior, PID_value.integral, VELOCIDADEMAXIMA);

	if (Dist <= 270)
	{
		PID_value = 0;
	}else if(Dist > 270)
	{
		PID_value = 1;
	}

	//vl = PID_value * 15;    //* 0.80221917;
	//vr = PID_value * 15;   //* 0.78221917 bateria cheia 0.85333 3/4 de bateria (robo 1) 

	vl = PID_value * CV_motor_esquerdo;
	vr = PID_value * CV_motor_direito; // * 0.80221917;

	printf("dist %.3f k %.3f Theta %.3f vl %.3f vr %.3f \n",Dist, k, ModTheta,vl,vr);
	//printf("Robot POS=<%9.2f,%9.2f>",rX,rY);


	//if(vr > VELOCIDADEMAXIMA)vr = VELOCIDADEMAXIMA;
	//if(vl > VELOCIDADEMAXIMA)vl = VELOCIDADEMAXIMA;

	movimento.R = vr;
	movimento.L = vl;

	command(true,indice,-vr,-vr,vl,vl,movimento.speed_x,movimento.speed_z);

	if (Dist <= 180)
	{
		movimento.verifica = 1;
	}else	{movimento.verifica= 0;}
		return movimento;
}
