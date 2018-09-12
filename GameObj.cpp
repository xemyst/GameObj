#include "GameObj.h"


GameObj::GameObj()
{
}

GameObj::~GameObj()
{
}

int GameObj::objDistance(GameObj object){
    return getX() - object.getX();
}

int GameObj:: getX(){
    return x;
}

void GameObj::setX(int x){
    this->x = x;
}

int GameObj:: getY(){
    return y;
}

void GameObj::setY(int y){
    this->y = y;
}

