#include "CHORSE.h"


CHORSE::CHORSE() {
	mMove = LEFT;
	countSpeed = MAX_SPEED;
	form1 = { {17, 220}, {32, 219} };
	form2 = { {17, 220}, {32, 178} };
}

CHORSE::CHORSE(const CHORSE& ho)
{
	mX = ho.mX;
	mY = ho.mY;
	mColor = ho.mColor;
	mSpeed = ho.mSpeed;
	mMove = ho.mMove;
	form1 = ho.form1;
	form2 = ho.form2;
}

CHORSE::CHORSE(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
	form1 = { {17, 220}, {32, 219} };
	form2 = { {17, 220}, {32, 178} };
}

CHORSE::~CHORSE() {
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

// set các số liệu của đối tượng
void CHORSE::set(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

// set form hình của đối tượng
void CHORSE::setForm(const vector<vector<short>>& _form1, const vector<vector<short>>& _form2)
{
	form1 = _form1;
	form2 = _form2;
}

short CHORSE::getHeight() const {
	return form1.size();
}

short CHORSE::getWidth() const {
	if (form1.size() > 0)
		return form1[0].size();
	return 0;
}

void CHORSE::tell() {
	PlaySound(TEXT("OST/VoiceHorse.wav"), NULL, SND_ASYNC);
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