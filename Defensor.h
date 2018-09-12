#ifndef DEFENSOR_H
#define DEFENSOR_H
#include <Robo.h>

class Defensor : public Robo
{
public:
    Defensor();
    Defensor(Robo antiguo);
    ~Defensor();
    int getTpe() override;
public:

};

#endif // DEFENSOR_H
