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
	CVEHICLE(const CVEHICLE&);
	~CVEHICLE();

	void setX(short X);
	void setY(short Y);
	void setColor(short);
	void setSpeed(short);
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&) = 0;

	short getX() const;
	short getY() const;
	int getColor() const;

	virtual short getHeight() const = 0;
	virtual short getWidth() const = 0;

	//move là hướng xe chạy qua trái hay phải
	void drawVehicle(vector<vector<short>>, short) const;
	virtual void move() = 0;
	virtual void draw() const = 0;
};

