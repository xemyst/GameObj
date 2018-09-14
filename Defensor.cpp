#include "Defensor.h"

Defensor::Defensor()
{
}
Defensor::Defensor(Robo antiguo)
{
    setX(antiguo.getX());
    setY(antiguo.getY());
    
}

Defensor::~Defensor()
{
}
