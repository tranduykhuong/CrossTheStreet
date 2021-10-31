#include "CRABBIT.h"

CRABBIT::CRABBIT()
{
	mMove = LEFT;
	countSpeed = MAX_SPEED;
}

CRABBIT::~CRABBIT()
{
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

void CRABBIT::set(const short& x, const short& y, const int& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

int CRABBIT::getHeight()
{
	return rabbitLeft_1.size();
}

int CRABBIT::getWidth()
{
	return rabbitLeft_1[0].size();
}

const vector<vector<char>>& CRABBIT::getDraw(const int& n)
{
	switch (n)
	{
	case 1:
		return rabbitLeft_1;
	case 2:
		return rabbitLeft_2;
	case 3:
		return rabbitRight_1;
	default:
		return rabbitRight_2;
		break;
	}
}

void CRABBIT::tell()
{
	PlaySound(TEXT("VoiceRabbit.wav"), NULL, SND_SYNC);
}

void CRABBIT::move()
{
	if (countSpeed > mSpeed) {
		countSpeed--;
		return;
	}

	if (mMove == RIGHT) {
		mX++;

		//nếu con thỏ chạm biên phải thì cho xuất phát lại
		if (mX == sRIGHT)
			setX((getWidth() * (-1)));
	}
	else {
		mX--;

		//nếu con thỏ chạm biên trái thì cho xuất phát lại
		if (mX == sLEFT - getWidth() - 1)
			setX(sRIGHT);
	}
	countSpeed = MAX_SPEED;
}

void CRABBIT::draw() {
	if (mMove == RIGHT) {
		if (mX % 2 == 0)
			CANIMAL::drawAnimal(rabbitRight_1, mMove);
		else
			CANIMAL::drawAnimal(rabbitRight_2, mMove);
	}
	else {
		if (mX % 2 == 0)
			CANIMAL::drawAnimal(rabbitLeft_1, mMove);
		else
			CANIMAL::drawAnimal(rabbitLeft_2, mMove);
	}
}