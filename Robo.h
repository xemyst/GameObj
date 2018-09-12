#ifndef ROBO_H
#define ROBO_H
#include <iostream>
#include <GameObj.h>
#include <Bola.h>
class Robo : public GameObj
{
public:
    Robo();
    ~Robo();
    void setBola(Bola *ball);
    void where();
private:
    Bola *bola;
};

#endif // ROBO_H
