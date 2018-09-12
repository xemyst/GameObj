#include "Robo.h"

Robo::Robo()
{
}

Robo::~Robo()
{
}

void Robo::setBola(Bola *bola){
    this->bola = bola;
}

void Robo::where(){
    std::cout << "X: " << bola->getX() << " Y: "<< bola->getY()<< '\n';
}