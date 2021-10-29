#include "CCAR.h"

CCAR::CCAR() {
	mType = 1;
	mMove = LEFT;
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
	vector<vector<short>> car;
	if (mMove == LEFT) {
		if (mType == 1)
			car = carLeft1;
		else car = carLeft2;

		while (1) {
			CVEHICLE::drawVehicle(car, mMove);	//vẽ xe
			mX--;								//giảm tọa độ
			if (mX == sLEFT - car[0].size() - 1)					//nếu xe chạm biên trái thì cho xuất phát lại
				mX = sRIGHT;

			Sleep(mSpeed);
		}
	}
	else {
		if (mType == 1)
			car = carRight1;
		else car = carRight2;

		while (1) {
			CVEHICLE::drawVehicle(car, mMove);	//vẽ xe
			mX++;								//tăng tọa độ
			if (mX == sRIGHT)					//nếu xe chạm biên phải thì cho xuất phát lại
				mX = (car[0].size()) * (-1);

			Sleep(mSpeed);
		}
	}
}