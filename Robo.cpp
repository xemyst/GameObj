#include "Robo.h"
Robo::Robo(Robo *antiguo)
{
}

Robo::Robo()
{
}

fieldPoint Robo::a_estrela();

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
    std::cout <<"type: " <<  equipo[id].getType() <<" id: " << id << " X: " << equipo[id].getX() << " Y: "<< equipo[id].getY()<< '\n';
}
void Robo::move(int x, int y){
    fieldPoint menorCaminho = a_estrela();
    moveRobot(menorCaminho);
}

fieldPoint Robo::a_estrela(){
    bool obstacle;
    fieldPoint menorCaminho;
	int menorPath = 100000;

    fieldPoint *paths = mapSquares(); //crear 8 caminos (NOT DONE)
    for(int x = 0; x < sizeof(paths); x++){
        obstacle = checkPath(obstaculo, paths[x]);//(NOT DONE)
    
        if(!obstacle){
            distance_prox = objDistance(paths[x]);
            distance_final = paths[x].objDistance(bola);
            distance = distance_prox + distance_final;
        }
    	
        if(distance < menorPath){
            menorPath = distance;
	    menorCaminho = paths[x]
        }
    }
    
    
    return menorCaminho;
}

fieldPoint mapSquares(){

 fieldPoint *paths = new fieldPoint[8];
 int params = 180;
 
 paths[0].update(getX()-params,getY()+params); 
 paths[1].update(getX(),getY()+params);        
 paths[2].update(getX()+params,getY()+params); 
 paths[3].update(getX()+params,getY());        
 paths[4].update(getX()+params,getY()-params); 
 paths[5].update(getX(),getY()-params);        
 paths[6].update(getX()-params,getY()-params); 
 paths[7].update(getX()-params,getY());        

 return paths;
}

void moveRobot(fieldPoint manorCaminho){ 
    
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
    
    
    dist = objDistance(puntoFinal);//Cada posiçao, (Atacante, defensor) possuira seu ponto final. Atacante = bola, Defensor = linha de defesa
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
