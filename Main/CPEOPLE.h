#pragma once
#include"CONSOLE.h"


class CPEOPLE
{
private:
	vector<vector<int>> peopleWait = { {32, 2, 32}, {47, 245, 92}, {47, 32, 92} };
	vector<vector<int>> peopleUp = { {92, 2, 47}, {32, 245, 32}, {47, 32, 92} };
	vector<vector<int>> peopleLeft = { {92, 2, 32}, {32, 245, 92}, {124, 32, 92} };
	vector<vector<int>> peopleRight = { {32, 2, 47}, {47, 245, 32}, {47, 32, 124} };
	vector<vector<int>> peopleDown = { {92, 2, 47}, {32, 245, 32}, {60, 32, 62} };

	const short heightRoad = SCREEN_GAME_HEIGHT / NUMBER_ROAD;

private:
	short mX, mY;
	bool mState;
	short mSpeed;
	int mColor;

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
	
	short getSpeed() const;
	short getX() const;
	short getY() const;
	int getColor() const;
	short getHeightPeople() const { return peopleWait.size(); }
	short getWidthPeople() const { return peopleWait[0].size(); }

	void draw(int);

};

