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

bool Robo::check(float pathX, float pathY, float RoboX, float RoboY)
{
   int params = 270;

    if ((RoboX < ((pathX)+params)) && (RoboX  > ((pathX)-params)) && (RoboY < ((pathY)+params)) && (RoboY > ((pathY)-params)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Robo::FieldSquares Robo::aEstrela(float RoboX, float RoboY, float RoboTheta, float BolaX, float BolaY)
{
int params = 180;
struct FieldSquares path[8];
struct FieldSquares menorCaminho;

path[0].X = (RoboX - params);
path[0].Y = (RoboY + params);
path[1].X = (RoboX);
path[1].Y = (RoboY + params);
path[2].X = (RoboX + params);
path[2].Y = (RoboY + params);
path[3].X = (RoboX + params);
path[3].Y = (RoboY);
path[4].X = (RoboX + params);
path[4].Y = (RoboY - params);
path[5].X = (RoboX);
path[5].Y = (RoboY - params);
path[6].X = (RoboX - params);
path[6].Y = (RoboY - params);
path[7].X = (RoboX - params);
path[7].Y = (RoboY);

float menor=100000, f;
    float Dist_Prox,Dist_Final;

    for (int i=0;i < 8; i++)
    {
        for (int j = 0; j < 6;j++)
        {
            float ObstaculoAzulX = Azul[j].getX();
            float ObstaculoAzulY = Azul[j].getY();
	    float ObstaculoAmareloX = Amarelo[j].getX();
            float ObstaculoAmareloY = Amarelo[j].getY();
            bool checkBlue = Robo::check(path[i].X, path[i].Y, ObstaculoAzulX, ObstaculoAzulY);
	    bool checkYellow = Robo::check(path[i].X, path[i].Y, ObstaculoAmareloX, ObstaculoAmareloY);

            if (checkBlue == true || checkYellow == true)
            {
            f = 150000;/*coloca um valor muito alto, para o caminho que tiver obstaculo ser desconsiderado*/
            }
            else
            {
                Dist_Prox = sqrt((RoboX - path[i].X)*(RoboX - path[i].X) + (RoboY - path[i].Y)*(RoboY - path[i].Y));//distancia do proximo ponto
                Dist_Final = sqrt( (path[i].X - BolaX)*(path[i].X - BolaX) + (path[i].Y - BolaY)*(path[i].Y - BolaY) );//distancia do final
                f = Dist_Prox + Dist_Final;
            }

            if (f < menor)
            {
                menor = f;
                menorCaminho.X = path[i].X;
                menorCaminho.Y = path[i].Y;
	    }
        }
    }

    return (menorCaminho);
}

void Robo::Menor_caminho_Update(struct FieldSquares Cordenadas)
{
Robo::Menor_caminho.X = Cordenadas.X;
Robo::Menor_caminho.Y = Cordenadas.Y;
}

float Robo::getMenor_caminhoX()
{
return Robo::Menor_caminho.X;
}

float Robo::getMenor_caminhoY()
{
return Robo::Menor_caminho.Y;
} 


