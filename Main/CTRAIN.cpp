#include "CTRAIN.h"

CTRAIN::CTRAIN() {
	mMove = LEFT;
	countSpeed = MAX_SPEED;
	form = { {219,219,219,219} };
}

CTRAIN::CTRAIN(const CTRAIN& ca)
{
	mX = ca.mX;
	mY = ca.mY;
	mColor = ca.mColor;
	mSpeed = ca.mSpeed;
	mMove = ca.mMove;
	form = ca.form;
}

CTRAIN::CTRAIN(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
	form = { {219,219,219,219} };
}

CTRAIN::~CTRAIN() {
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

// set các thông số cho đối tượng
void CTRAIN::set(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

short CTRAIN::getHeight() const {
	return form.size();
}

short CTRAIN::getWidth() const {
	if (form.size() > 0)
		return form[0].size();
	return 0;
}

void CTRAIN::move() {
	if (countSpeed > mSpeed) {
		countSpeed--;
		return;
	}

	if (mMove == LEFT) {
		mX--;								//giảm tọa độ
		if (mX == sLEFT - getWidth() - 1)	//nếu xe chạm biên trái thì cho xuất phát lại
			mX = sRIGHT;
	}
	else {
		mX++;								//tăng tọa độ
		if (mX == sRIGHT)					//nếu xe chạm biên phải thì cho xuất phát lại
			mX = (getWidth()) * (-1);
	}
	countSpeed = MAX_SPEED;
}

void CTRAIN::draw() const {
	CVEHICLE::drawVehicle(form, mMove);	//vẽ xe
}

void CTRAIN::tell() const
{
	PlaySound(TEXT("OST/trainhorn.wav"), NULL, SND_ASYNC);
}

void CTRAIN::setForm(const vector<vector<short>>& form1, const vector<vector<short>>& form2)
{
	form = form1;
}