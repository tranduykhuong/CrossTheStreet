#pragma once
#include"CONSOLE.h"
#include"CANIMAL.h"
#include"CVEHICLE.h"
#include"CTRUCK.h"

class CPEOPLE
{
private:
	static vector<vector<short>> peopleWait;
	static vector<vector<short>> peopleUp;
	static vector<vector<short>> peopleLeft;
	static vector<vector<short>> peopleRight;
	static vector<vector<short>> peopleDown;

	static vector<vector<int>> peopleShade;

private:
	short mX, mY;
	bool mState;
	short mSpeed;
	int mColor;
	int colorShade;

public:
	CPEOPLE();
	CPEOPLE(short, short);

	void up();
	void down();
	void left();
	void right();

	bool isWin() const;
	bool isDead() const;

	void setState(bool);
	void setSpeed(short);
	void setPosition(short, short);
	void setColor(int);
	void setColorShade(int);
	void setShade(vector<vector<int>> shade) {
		this->peopleShade = shade;
	}

	short getSpeed() const;
	short getX() const;
	short getY() const;
	int getColor() const;
	int getColorShade() const;
	short getHeightPeople() const { return peopleWait.size(); }
	short getWidthPeople() const { return peopleWait[0].size(); }

	bool isImpact(const vector<CVEHICLE*>&, short);
	bool isImpact(const vector<CANIMAL*>&, short);

	void draw(int);

};

