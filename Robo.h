#ifndef ROBO_H
#define ROBO_H
#include <iostream>
#include "GameObj.h"
#include "Bola.h"
#include "Enemigo.h"
#include "FieldPoint.h"

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
    void move(int x, int y);
	FieldPoint a_estrela(int toX, int toY);
	void moveRobot(FieldPoint menorCaminho);
	FieldPoint* mapSquares();
	bool checkPath(GameObj one, GameObj two);
private:
    Bola *bola;
    Enemigo *enemigos;
    Robo *equipo;
    int vmax = 15;
    
    struct params_movimento{
      int R, L, speed_z, speed_x;
      bool verifica = 0;
    };
};

#endif // ROBO_H
