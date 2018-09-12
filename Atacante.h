#ifndef ATACANTE_H
#define ATACANTE_H
#include <Robo.h>
class Atacante : public Robo
{
public:
    Atacante();
    Atacante(Robo robo);
    ~Atacante();
   int getTpe() override;

};

#endif // ATACANTE_H
