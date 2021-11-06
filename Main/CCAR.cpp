#include "CCAR.h"

CCAR::CCAR() {
	mMove = LEFT;
	countSpeed = MAX_SPEED;
	form = { {} };
}

CCAR::CCAR(short x, short y, short color, short speed, short move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
	form = { {} };
}

CCAR::~CCAR() {
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

void CCAR::set(short x, short y, short color, short speed, short move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

short CCAR::getHeight() const {
	return form.size();
}

short CCAR::getWidth() const {
	return form[0].size();
}

void CCAR::move() {
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

void CCAR::draw() const {
	CVEHICLE::drawVehicle(form, mMove);	//vẽ xe
}

void CCAR::setForm(const vector<vector<short>>& form1, const vector<vector<short>>& form2)
{
	form = form1;
}