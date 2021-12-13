﻿#include "CRABBIT.h"

CRABBIT::CRABBIT()
{
	mMove = LEFT;
	countSpeed = MAX_SPEED;
	form1 = { {17, 220}, {32, 219} };
	form2 = { {17, 220}, {32, 178} };
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
	form1 = { {17, 220}, {32, 219} };
	form2 = { {17, 220}, {32, 178} };
}

CRABBIT::~CRABBIT()
{
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

// set các số liệu của đối tượng
void CRABBIT::set(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

// set form hình của đối tượng
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
	if (form1.size() > 0)
		return form1[0].size();
	return 0;
}

void CRABBIT::tell()
{
	PlaySound(TEXT("OST/VoiceRabbit.wav"), NULL, SND_ASYNC);
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