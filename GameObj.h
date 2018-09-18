#ifndef GAMEOBJ_H
#define GAMEOBJ_H
#include <math.h>
class GameObj
{

public:
int x;
    int y;
    GameObj();
    ~GameObj();
    int objDistance(GameObj object);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void update(int x, int y);
    
    struct fieldPoint{
        int x;
        int y;
    };
};

#endif // GAMEOBJ_H
