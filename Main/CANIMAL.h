#pragma once
#include "CONSOLE.h"

#define MAX_SPEED 5

class CANIMAL
{
protected:
	short mX, mY;
	short mSpeed;
	short mColor;
	short mMove;
public:
	CANIMAL();
	CANIMAL(const CANIMAL&);
	CANIMAL(const short&, const short&, const short&, const short&, const short&);
	~CANIMAL();

	void setX(const short&);
	void setY(const short&);
	void setSpeed(const short&);
	void setColor(const short&);
	void setMove(const short&);
	virtual void set(const short&, const short&, const short&, const short&, const short&) = 0;
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&) = 0;

	short getX() const;
	short getY() const;
	short getColor() const;
	short getSpeed() const;
	short getMove() const;

	virtual short getHeight() const = 0;
	virtual short getWidth() const = 0;


	void drawAnimal(const vector<vector<short>>&, const short&) const;
	virtual void tell() = 0;
	virtual void move() = 0;
	virtual void draw() const = 0;
};