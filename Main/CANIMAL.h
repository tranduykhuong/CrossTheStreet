#pragma once
#include "CONSOLE.h"

class CANIMAL
{
protected:
	short mX, mY, mSpeed;
	int  mColor;
public:
	CANIMAL();
	~CANIMAL();

	void setX(const short&);
	void setY(const short&);
	void setSpeed(const short&);
	void setColor(const int&);

	short getX();
	short getY();
	int getColor();
	short getSpeed();

	void drawAnimal(const vector<vector<char>>&, const short&);
	virtual void tell() {};
	virtual void move() {};
};