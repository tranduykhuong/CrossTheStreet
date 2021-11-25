#pragma once
#include "CONSOLE.h"

#define MAX_SPEED 5

class CVEHICLE
{
protected:
	short mX, mY;
	short mColor;
	short mSpeed;
	short mMove;

	void drawVehicle(vector<vector<short>>, short) const;

public:
	CVEHICLE();
	CVEHICLE(const short&, const short&, const short&, const short&, const short&);
	CVEHICLE(const CVEHICLE&);
	~CVEHICLE();

	short getX() const;
	short getY() const;
	short getColor() const;
	short getSpeed() const;
	short getMove() const;

	void setX(const short& X);
	void setY(const short& Y);
	void setColor(const short&);
	void setSpeed(const short&);
	void setMove(const short&);

	virtual void set(const short&, const short&, const short&, const short&, const short&) = 0;
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&) = 0;

	virtual short getHeight() const = 0;
	virtual short getWidth() const = 0;

	virtual void tell() const = 0;
	virtual void draw() const = 0;
	virtual void move() = 0;
};

