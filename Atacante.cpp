#include "Atacante.h"

Atacante::Atacante()
{
}
Atacante::Atacante(Robo antiguo)
{
    setX(antiguo.getX());
    setY(antiguo.getY());
    
}
Atacante::~Atacante()
{
}
