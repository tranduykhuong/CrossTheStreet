#pragma once
#include "CONSOLE.h"

#define MAX_SPEED 5

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
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&) = 0;

	short getX() const;
	short getY() const;
	int getColor() const;
	short getSpeed() const;
	virtual short getHeight() const = 0;
	virtual short getWidth() const = 0;

	void drawAnimal(const vector<vector<short>>&, const short&) const;
	virtual void tell() = 0;
	virtual void move() = 0;
	virtual void draw() const = 0;
};