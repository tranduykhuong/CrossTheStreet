#pragma once
#include"CONSOLE.h"


class CPEOPLE
{
private:
	const vector<vector<int>> peopleWait = { {32, 2, 32}, {47, 245, 92}, {47, 32, 92} };
	const vector<vector<int>> peopleUp = { {92, 2, 47}, {32, 245, 32}, {47, 32, 92} };
	const vector<vector<int>> peopleLeft = { {92, 2, 32}, {32, 245, 92}, {124, 32, 92} };
	const vector<vector<int>> peopleRight = { {32, 2, 47}, {47, 245, 32}, {47, 32, 124} };
	const vector<vector<int>> peopleDown = { {92, 2, 47}, {32, 245, 32}, {60, 32, 62} };

	const short widthPeople = peopleWait.size();
	const short heightPeople = peopleWait.size();
	const short heightRoad = SCREEN_GAME_HEIGHT / NUMBER_ROAD;

private:
	short mX, mY;
	bool mState;
	short mSpeed;
	int mColor;

public:
	CPEOPLE();
	CPEOPLE(short, short);
	~CPEOPLE();

	void up();
	void down();
	void left();
	void right();

	bool isWin();
	bool isDead();

	void setState(bool);
	void setSpeed(short);
	void setPosition(short, short);
	void setColor(int);
	
	short getSpeed();
	short getX();
	short getY();
	int getColor();

	void draw(int);
};

