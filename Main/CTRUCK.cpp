#include "CTRUCK.h"

CTRUCK::CTRUCK() {
	mMove = RIGHT;
	countSpeed = MAX_SPEED;
	form = { {219, 32}, {219, 219} };
}

CTRUCK::CTRUCK(const CTRUCK& tr)
{
	mX = tr.mX;
	mY = tr.mY;
	mColor = tr.mColor;
	mSpeed = tr.mSpeed;
	mMove = tr.mMove;
	form = tr.form;
}

CTRUCK::CTRUCK(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
	form = { {219, 32}, {219, 219} };
}

CTRUCK::~CTRUCK() {
	mMove = 0;
}

// set các thông số cho đối tượng
void CTRUCK::set(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

short CTRUCK::getWidth() const {
	if (form.size() > 0)
		return form[0].size();
	return 0;
}

short CTRUCK::getHeight() const {
	return form.size();
}

void CTRUCK::move() {
	if (countSpeed > mSpeed) {
		countSpeed--;
		return;
	}

	if (mMove == LEFT) {
		mX--;								//giảm tọa độ
		if (mX == sLEFT - getWidth() - 1)					//nếu xe chạm biên trái thì cho xuất phát lại
			mX = sRIGHT;
	}
	else {
		mX++;								//tăng tọa độ
		if (mX == sRIGHT)					//nếu xe chạm biên phải thì cho xuất phát lại
			mX = (getWidth()) * (-1);
	}
	countSpeed = MAX_SPEED;
}

void CTRUCK::draw() const {
	CVEHICLE::drawVehicle(form, mMove);	//vẽ xe
}

void CTRUCK::tell() const
{
	PlaySound(TEXT("OST/tructhorn.wav"), NULL, SND_ASYNC);
}

void CTRUCK::setForm(const vector<vector<short>>& form1, const vector<vector<short>>& form2)
{
	form = form1;
}