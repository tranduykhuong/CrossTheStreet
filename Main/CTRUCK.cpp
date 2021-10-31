#include "CTRUCK.h"

CTRUCK::CTRUCK() {
	mType = 1;
	mMove = RIGHT;
	countSpeed = MAX_SPEED;
}

CTRUCK::~CTRUCK() {
	mType = 0;
	mMove = 0;
}

void CTRUCK::set(short x, short y, short color, short speed, short type, short move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mType = type;
	mMove = move;
}

short CTRUCK::getWidth() const {
	return truckLeft1[0].size();
}

short CTRUCK::getHeight() const {
	return truckLeft1.size();
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

void CTRUCK::draw() {
	vector<vector<short>> truck;
	if (mType == 1) {
		if (mMove == LEFT)
			truck = truckLeft1;
		else
			truck = truckRight1;
	}
	else {
		if (mMove == LEFT)
			truck = truckLeft2;
		else
			truck = truckRight2;
	}
	
	CVEHICLE::drawVehicle(truck, mMove);	//vẽ xe
}