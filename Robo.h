#ifndef ROBO_H
#define ROBO_H
#include <iostream>
#include <math.h>
#include "fieldPoint.cpp"

FieldPoint Amarelo[12];
FieldPoint Azul[12];
FieldPoint Bola;

class Robo
{

private:

    int vmax = 15;
    
    struct params_movimento{
      int R, L, speed_z, speed_x;
      bool verifica = 0;
    };

public:
    Robo(Robo *antiguo);
    Robo();
    ~Robo();
 
 struct FieldSquares{
	float X;
	float Y;
    };

struct FieldSquares Menor_caminho;

	//funçao de checagem do caminho

    bool check(float pathX,float pathY, float ObstaculoX, float ObstaculoY);
	
	//funçao de movimento
    
    struct FieldSquares aEstrela(float RoboX, float RoboY, float RoboTheta, float BolaX, float BolaY);

	//funçoes de Menor caminho

    void Menor_caminho_Update(struct FieldSquares Cordenadas);
    float getMenor_caminhoX();
    float getMenor_caminhoY();	


};

#endif // ROBO_H
