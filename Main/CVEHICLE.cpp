#include "CVEHICLE.h"

CVEHICLE::CVEHICLE() {
	mX = mY = mSpeed = 0;
	mColor = ColorGame::black;
	mMove = LEFT;
}

CVEHICLE::CVEHICLE(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

CVEHICLE::CVEHICLE(const CVEHICLE& src) {
	mX = src.mX;
	mY = src.mY;
	mColor = src.mColor;
	mSpeed = src.mSpeed;
}

CVEHICLE::~CVEHICLE() {
	mX = mY = mSpeed = 0;
	mColor = ColorGame::black;
}

void CVEHICLE::setX(const short& X) {
	mX = X;
}
void CVEHICLE::setY(const short& Y) {
	mY = Y;
}
void CVEHICLE::setColor(const short& color) {
	mColor = color;
}
void CVEHICLE::setSpeed(const short& speed) {
	mSpeed = speed;
}

void CVEHICLE::setMove(const short& _move)
{
	mMove = _move;
}

short CVEHICLE::getX() const {
	return mX;
};
short CVEHICLE::getY() const {
	return mY;
};
short CVEHICLE::getColor() const {
	return mColor;
}

short CVEHICLE::getSpeed() const
{
	return mSpeed;
}

short CVEHICLE::getMove() const
{
	return mMove;
}

//move là hướng xe chạy qua trái hay phải
void CVEHICLE::drawVehicle(vector<vector<short>> form, short move) const {

	CONSOLE::textcolor(mColor);
	short heightVehicle = form.size();		//chiều cao của xe
	short widthVehicle = form[0].size();	//chiều dài xe
	short startX, endX, idx;
	// bắt đầu vẽ từ điểm nào trên chiếc xe, kết thúc vẽ từ điểm nào trên chiếc xe và vị trí xuất xe

	//xử lý va chạm biên
	if (mX - SCREEN_GAME_RECT_X < 0) {				//xử lý biên trái
		startX = -(mX - SCREEN_GAME_RECT_X);
		endX = widthVehicle;
		idx = SCREEN_GAME_RECT_X + 1;
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
	switch (move) {
	case Key::RIGHT: {

		for (int i = 0; i < heightVehicle; i++) {
			if (idx != SCREEN_GAME_RECT_X + 1) {
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