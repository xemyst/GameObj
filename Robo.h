#ifndef ROBO_H
#define ROBO_H
#include <iostream>
#include <GameObj.h>
#include <Bola.h>
#include <Enemigo.h>
class Robo : public GameObj
{
public:
    Robo(Robo *antiguo);
    Robo();
    ~Robo();
    void setBola(Bola *ball);
    void where();
    void whereEnemigo(int id);
    void whereAlie(int id);
    void setEnemigos(Enemigo enemigos[6]);
    void setEquipo(Robo equipo[6]);
    virtual int getTpe() {};
    
private:
    Bola *bola;
    Enemigo *enemigos;
    Robo *equipo;
};

#endif // ROBO_H
