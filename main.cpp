#include <stdio.h>
#include <iostream>
#include <GameObj.h>
#include <Bola.h>
#include <Defensor.h>
#include <Robo.h>

int main(int argc, char **argv)
{
	printf("hello world \n");
    GameObj obj[2];
    obj[0] = Bola();
    obj[0].setX(20);
    obj[0].setY(40);
    Robo j;
    j.setX(80);
    std::cout << j.objDistance(obj[0]);
    return 0;
}
