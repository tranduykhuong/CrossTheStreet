#include "CVEHICLE.h"

CVEHICLE::CVEHICLE() {
	mX = mY = mSpeed = 0;
	mColor = ColorGame::black;
}
CVEHICLE::~CVEHICLE() {
	mX = mY = mSpeed = 0;
	mColor = ColorGame::black;
}

void CVEHICLE::setX(short X) {
	mX = X;
}
void CVEHICLE::setY(short Y) {
	mY = Y;
}
void CVEHICLE::setColor(short color) {
	mColor = color;
}
void CVEHICLE::setSpeed(short speed) {
	mSpeed = speed;
}

short CVEHICLE::getX() const {
	return mX;
};
short CVEHICLE::getY() const {
	return mY;
};
int CVEHICLE::getColor() const {
	return mColor;
}

//move là hướng xe chạy qua trái hay phải
void CVEHICLE::drawVehicle(vector<vector<short>> form, short move) {

	CONSOLE::textcolor(mColor);
	short heightVehicle = form.size();		//chiều cao của xe
	short widthVehicle = form[0].size();	//chiều dài xe
	short startX, endX, idx;
	// bắt đầu vẽ từ điểm nào trên chiếc xe, kết thúc vẽ từ điểm nào trên chiếc xe và vị trí xuất xe

	switch (move) {
	case Key::RIGHT: {

		//xử lý biên trái
		if (mX < 0) {
			startX = -mX;
			endX = widthVehicle;
			idx = 1;
		}
		else if (mX + widthVehicle >= sRIGHT) {	//xử lý biên phải
			startX = 0;
			endX = sRIGHT - mX - 1;
			idx = mX + 1;
		}
		else {						//lúc bình thường
			startX = 0;
			endX = widthVehicle;
			idx = mX + 1;
		}

		//xuất xe
		for (int i = 0; i < heightVehicle; i++) {
			if (idx != 1) {
				CONSOLE::gotoXY(idx - 1, mY + i);	//xóa vết nếu nó không chạm biên trái
				cout << " ";
			}
			else CONSOLE::gotoXY(idx, mY + i);

			for (int j = startX; j < endX; j++)
				cout << char(form[i][j]);
		}
		break;
	}
	case Key::LEFT: {

		//xử lý va chạm biên
		if (mX + widthVehicle >= sRIGHT) {	//xử lý biên phải
			startX = 0;
			endX = sRIGHT - mX - 1;
			idx = mX + 1;
		}
		else if (mX < 0) {				//xử lý biên trái
			startX = -mX;
			endX = widthVehicle;
			idx = 1;
		}
		else {							//lúc bình thường
			startX = 0;
			endX = widthVehicle;
			idx = mX + 1;
		}

		//xuất xe
		for (int i = 0; i < heightVehicle; i++) {
			CONSOLE::gotoXY(idx, mY + i);

			for (int j = startX; j < endX; j++)
				cout << char(form[i][j]);

			if (mX + widthVehicle + 1 < sRIGHT)
				cout << " ";					//xóa vết nếu nó không chạm biên phải
		}

		break;
	}
	}
}