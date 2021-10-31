#include "CCAR.h"

CCAR::CCAR() {
	mType = 1;
	mMove = LEFT;
	countSpeed = MAX_SPEED;
}

CCAR::~CCAR() {
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mType = 0;
	mMove = 0;
}

void CCAR::set(short x, short y, short color, short speed, short type, short move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mType = type;
	mMove = move;
}

short CCAR::getHeight() const {
	return carLeft1.size();
}

short CCAR::getWidth() const {
	return carLeft1[0].size();
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

void CCAR::draw() {
	vector<vector<short>> car;
	if (mType == 1) {
		if (mMove == LEFT)
			car = carLeft1;
		else
			car = carRight1;
	}
	else {
		if (mMove == LEFT)
			car = carLeft2;
		else
			car = carRight2;
	}
	CVEHICLE::drawVehicle(car, mMove);	//vẽ xe
}