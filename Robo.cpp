#include "Robo.h"

Robo::Robo(Robo *antiguo)
{
}

Robo::Robo()
{
}



Robo::~Robo()
{
}

void Robo::setBola(Bola *bola){
    this->bola = bola;
}

void Robo::setEnemigos(Enemigo enemigos[6]){
    this-> enemigos = enemigos;
}
void Robo::setEquipo(Robo equipo[6]){
    this-> equipo = equipo;
}

void Robo::where(){
    std::cout << "X: " << bola->getX() << " Y: "<< bola->getY()<< '\n';
}
void Robo::whereEnemigo(int id){
    std::cout << "id: " << id << "X: " << enemigos[id].getX() << " Y: "<< enemigos[id].getY()<< '\n';
}
void Robo::whereAlie(int id){
    std::cout <<"type: " <<  equipo[id].getTpe() <<" id: " << id << " X: " << equipo[id].getX() << " Y: "<< equipo[id].getY()<< '\n';
}
void Robo::move(int x, int y){
    struct fieldPoint menorCamino = a_estrela();
    moveRobot(menorCamino);
}

struct fieldPoint Robo::a_estrela(){
    bool obstacle;
    
    mapSquares(); //crear 8 caminos (NOT DONE)
    for(int x = 0; x < 8; x++){
        obstacle = checkPath(obstaculo, camino);//(NOT DONE)
    
        if(!obstacle){
            distance_prox = objDistance(camino(candidato));
            distance_final = camino.objDistance(bola);
            distance = distance_prox + distance_final;
        }
    
        if(ditance < menorPath){
            //marcar este candidato como menor;
        }
    }
    
    
    return menorCamino;
}

void moveRobot(struct fieldPoint manorCamino){
    
    PID pid_motor_dereito;
    PID pid_motor_esquerdo;
    
    //init PID
    pid_motor_dereito.Init(0.04,0.0,0.0);
    pid_motor_esquerdo.Init(-0.04,0.0,0.0);
    
    //variaves de set point (SP) e control Variable(CV)
    double SP = 0.0, CV_motor_direito = 0.0, CV_motor_esquerdo = 0.0;
    
    //struct{
    //chute 
    movimento.speed_z = 0;
    movimento.speed_x = 0;
    //
    //}
    int PID_value;
    
    float theta, angulo, dist, vr, vl, modTheta;
    
    
    dist = objDistance(puntoFinal);//hasta el final
    
    angulo = (180/M_PI)*atan2(caminoY - getY(), caminoX - getX());
    theta = angulo - getTheta()*(180/M_PI);
    
    //ajusta ho angulo
    while(theta > 180) theta -= 360;
    while(theta < -180) theta += 360;
    
    modTheta = fabs(theta);
    
    
    CV_motor_dereito = pid_motor_dereito.UpdateOutput(SP, theta, vmax);
    CV_motor_esquerdo = pid_motor_esquerdo.UpdateOutput(SP, theta, vmax);
    
    if(dist <= 270)
    {
        PID_value = 0;
    }else{
        PID_value = 1;
    }
    
    vl = PID_value * CV_motor_esquerdo;
    vr = PID_value * CV_motor_dereito;
    
    
    movimento.R = vr;
    movimento.L = vl;
    
    //comando para gsim
    command(true,id,-vr,-vr,vl,vl,movimento.speed_x, movimento.speed_z)
    
    if(Dist <= 180)
    {
        movimento.verifica = 1;
    }else{
        movimento.verifica = 0;
    }
    
}

