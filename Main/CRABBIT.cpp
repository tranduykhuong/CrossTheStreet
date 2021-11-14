#include "CRABBIT.h"

CRABBIT::CRABBIT()
{
	mMove = LEFT;
	countSpeed = MAX_SPEED;
	form1 = { {} };
	form2 = { {} };
}

CRABBIT::CRABBIT(const CRABBIT& ra)
{
	mX = ra.mX;
	mY = ra.mY;
	mColor = ra.mColor;
	mSpeed = ra.mSpeed;
	mMove = ra.mMove;
	form1 = ra.form1;
	form2 = ra.form2;
}

CRABBIT::CRABBIT(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
	form1 = { {} };
	form2 = { {} };
}

CRABBIT::~CRABBIT()
{
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

void CRABBIT::set(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

void CRABBIT::setForm(const vector<vector<short>>& _form1, const vector<vector<short>>& _form2)
{
	form1 = _form1;
	form2 = _form2;
}

short CRABBIT::getHeight() const
{
	return form1.size();
}

short CRABBIT::getWidth() const
{
	return form1[0].size();
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

		//nếu Rabbit chạm biên phải thì cho xuất phát lại
		if (mX > sRIGHT)
			setX(sLEFT - getWidth());
	}
	else {
		mX--;

		//nếu Rabbit chạm biên trái thì cho xuất phát lại
		if (mX < sLEFT - getWidth() + 1)
			setX(sRIGHT - 1);
	}
	countSpeed = MAX_SPEED;
}

void CRABBIT::draw() const {
	if (mX % 2 == 0)
		CANIMAL::drawAnimal(form1, mMove);
	else
		CANIMAL::drawAnimal(form2, mMove);
}