#include "CHORSE.h"


CHORSE::CHORSE() {
	mMove = LEFT;
	countSpeed = MAX_SPEED;
	form1 = { {} };
	form2 = { {} };
}

CHORSE::CHORSE(const short& x, const short& y, const int& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
	form1 = { {} };
	form2 = { {} };
}

CHORSE::~CHORSE() {
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

void CHORSE::set(const short& x, const short& y, const int& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

void CHORSE::setForm(const vector<vector<short>>& _form1, const vector<vector<short>>& _form2)
{
	form1 = _form1;
	form2 = _form2;
}

short CHORSE::getHeight() const {
	return form1.size();
}

short CHORSE::getWidth() const {
	return form1[0].size();
}

void CHORSE::tell() {
	PlaySound(TEXT("VoiceHorse.wav"), NULL, SND_SYNC);
}

void CHORSE::move() {
	if (countSpeed > mSpeed) {
		countSpeed--;
		return;
	}

	if (mMove == RIGHT) {
		mX++;

		//nếu Horse chạm biên phải thì cho xuất phát lại
		if (mX > sRIGHT)
			setX(sLEFT - getWidth());
	}
	else {
		mX--;

		//nếu Horse chạm biên trái thì cho xuất phát lại
		if (mX < sLEFT - getWidth() + 1)
			setX(sRIGHT - 1);
	}
	countSpeed = MAX_SPEED;
}

void CHORSE::draw() const {
	if (mX % 2 == 0)
		CANIMAL::drawAnimal(form1, mMove);
	else
		CANIMAL::drawAnimal(form2, mMove);
}