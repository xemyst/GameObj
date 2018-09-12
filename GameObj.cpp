#include "GameObj.h"
#include <string>

GameObj::GameObj()
{
}

GameObj::~GameObj()
{
}

int GameObj::objDistance(GameObj object){
    int result;
    result = sqrt( (getX() - object.getX()) * (getX()-object.getX()) + (getY() -object.getY()) * (getY() - object.getY())); 
    return result;
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

void GameObj::update(int x, int y){
    this-> x = x;
    this -> y = y;
}
