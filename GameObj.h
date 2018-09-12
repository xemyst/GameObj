#ifndef GAMEOBJ_H
#define GAMEOBJ_H

class GameObj
{
private:
    int x;
    int y;
public:
    GameObj();
    ~GameObj();
    int objDistance(GameObj object);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);

};

#endif // GAMEOBJ_H
