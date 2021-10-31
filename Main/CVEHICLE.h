#pragma once
#include "CONSOLE.h"

#define MAX_SPEED 5

class CVEHICLE
{
protected:
	short mX, mY;
	short mColor;
	short mSpeed;

public:
	CVEHICLE();
	~CVEHICLE();

	void setX(short X);
	void setY(short Y);
	void setColor(short);
	void setSpeed(short);

	short getX() const;
	short getY() const;
	int getColor() const;

	//move là hướng xe chạy qua trái hay phải
	void drawVehicle(vector<vector<short>>, short);
	virtual void move() {};
};

