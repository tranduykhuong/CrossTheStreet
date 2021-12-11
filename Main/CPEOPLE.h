#pragma once
#include"CONSOLE.h"
#include"CANIMAL.h"
#include"CVEHICLE.h"

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

	bool isSound;
public:
	CPEOPLE();
	CPEOPLE(short, short);

	bool up();
	bool down();
	bool left();
	bool right();

	bool isWin() const;
	bool isDead() const;

	void setSound(bool);
	void setState(bool);
	void setSpeed(short);
	void setPosition(short, short);
	void setColor(short);
	void setColorShade(short);
	void setShade(vector<vector<int>> shade) {
		this->peopleShade = shade;
	}

	short getSpeed() const;
	short getX() const;
	short getY() const;
	short getColor() const;
	short getColorShade() const;
	vector<vector<int>> getPeopleShade();
	short getHeightPeople() const { return peopleWait.size(); }
	short getWidthPeople() const { return peopleWait[0].size(); }

	bool isImpact(const vector<CVEHICLE*>&, short);
	bool isImpact(const vector<CANIMAL*>&, short);

	void draw(int);
	void drawDie();
	void tell();
};

