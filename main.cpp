#include <stdio.h>
#include <iostream>
#include <GameObj.h>
#include <Bola.h>
#include <Enemigo.h>
#include <Robo.h>
#include <Defensor.h>
#include <Golero.h>
#include <Atacante.h>


int main(int argc, char **argv)
{
	printf("hello world \n");
    Bola bola = Bola(40,50);
    Robo *equipo = new Robo[6];
    Enemigo *enemigos = new Enemigo[6];
    Robo masperto = Robo();
    
    //init alies, width this all the alies can see the ball position, enemies, and alies
    for(int x = 0; x < 6; x++){
        equipo[x].setBola(&bola);
        equipo[x].setEnemigos(enemigos);
        equipo[x].setEquipo(equipo);
    }
    
    //the team never lose the index of other partner
    equipo[1].update(80,50);
    equipo[0].whereAlie(1);
    equipo[1] = Atacante(equipo[1]);
    equipo[0].whereAlie(1);
    equipo[1].update(39,90);
    equipo[0].whereAlie(1);
    equipo[1] = Defensor(equipo[1]);
    equipo[0].whereAlie(1);
    equipo[1].update(39,694);
    bola.update(60,50);
    enemigos[1].update(90,80);
    equipo[0].where();
    equipo[0].whereAlie(1);
    
    return 0;
}
