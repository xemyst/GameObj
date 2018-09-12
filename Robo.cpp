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