#include "fieldPoint.h"

FieldPoint::FieldPoint()
{
}
FieldPoint::~FieldPoint()
{
}

void FieldPoint::setX(float x){
    this->X = x;
}

void FieldPoint::setY(float y){
    this->Y = y;
}

void FieldPoint::setTheta(float Theta){
    this->Theta = Theta;
}

float FieldPoint::getY(){
    return Y;
}

float FieldPoint::getX(){
    return X;
}

float FieldPoint::getTheta(){
    return Theta;
}

