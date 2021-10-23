#include "CTRUCK.h"

CTRUCK::CTRUCK() {
	mType = 1;
	mMove = RIGHT;
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
	vector<vector<short>> truck;
	if (mMove == LEFT) {
		if (mType == 1)
			truck = truckLeft1;
		else truck = truckLeft2;

		while (1) {
			CVEHICLE::drawVehicle(truck, mMove);	//vẽ xe
			mX--;								//giảm tọa độ
			if (mX == sLEFT - truck[0].size() - 1)					//nếu xe chạm biên trái thì cho xuất phát lại
				mX = sRIGHT;

			Sleep(mSpeed);
		}
	}
	else {
		if (mType == 1)
			truck = truckRight1;
		else truck = truckRight2;

		while (1) {
			CVEHICLE::drawVehicle(truck, mMove);	//vẽ xe
			mX++;								//tăng tọa độ
			if (mX == sRIGHT)					//nếu xe chạm biên phải thì cho xuất phát lại
				mX = (truck[0].size()) * (-1);

			Sleep(mSpeed);
		}
	}
}