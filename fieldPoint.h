#ifndef FIELDPOINT_H
#define FIELDPOINT_H
#include <iostream>

class FieldPoint
{
public:
	FieldPoint();
	~FieldPoint();
	void setX(float x);
        void setY(float y);
	void setTheta(float Theta);
	float getX();
        float getY();
	float getTheta();
        
	

private:
	float Theta;
	float X;
	float Y;
};

#endif // FIELDPOINT_H
