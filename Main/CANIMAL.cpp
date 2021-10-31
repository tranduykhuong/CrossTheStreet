#include "CANIMAL.h"

CANIMAL::CANIMAL()
{
	mY = mX = mSpeed = 0;
	mColor = ColorGame::black;
}

CANIMAL::~CANIMAL()
{
	mX = mY = mSpeed = 0;
	mColor = ColorGame::black;
}

void CANIMAL::setX(const short& X)
{
	mX = X;
}

void CANIMAL::setY(const short& Y)
{
	mY = Y;
}

void CANIMAL::setColor(const int& color)
{
	mColor = color;
}

void CANIMAL::setSpeed(const short& speed)
{
	mSpeed = speed;
}

short CANIMAL::getX()
{
	return mX;
}

short CANIMAL::getY()
{
	return mY;
}

int CANIMAL::getColor()
{
	return mColor;
}

short CANIMAL::getSpeed()
{
	return mSpeed;
}

//move : Hướng di chuyển của đối tượng 
void CANIMAL::drawAnimal(const vector<vector<char>>& obj_1, const short& move)
{
	CONSOLE::textcolor(mColor);
	short heightObj = obj_1.size();			//chiều cao của đối tượng
	short widthObj = obj_1[0].size();		//chiều dài của đối tượng 
	short startX, endX, idx;
	// Tọa độ ngang điểm đầu, tọa độ ngang điểm cuối, và vị trí của obj

	switch (move) {
	case Key::RIGHT: {

		//xử lý biên trái
		if (mX < 0) {
			startX = -mX;
			endX = widthObj;
			idx = 1;
		}
		else if (mX + widthObj >= sRIGHT) {	//xử lý biên phải
			startX = 0;
			endX = sRIGHT - mX - 1;
			idx = mX + 1;
		}
		else {						//lúc bình thường
			startX = 0;
			endX = widthObj;
			idx = mX + 1;
		}

		//In ra màn hình đối tượng đó 
		for (int i = 0; i < heightObj; i++) {
			if (idx != 1) {
				CONSOLE::gotoXY(idx - 1, mY + i);	//xóa vết nếu nó không chạm biên trái
				cout << " ";
			}
			else CONSOLE::gotoXY(idx, mY + i);

			for (int j = startX; j < endX; j++)
				cout << obj_1[i][j];
		}
		break;
	}
	case Key::LEFT: {

		//xử lý va chạm biên
		if (mX + widthObj >= sRIGHT) {	//xử lý biên phải
			startX = 0;
			endX = sRIGHT - mX - 1;
			idx = mX + 1;
		}
		else if (mX < 0) {				//xử lý biên trái
			startX = -mX;
			endX = widthObj;
			idx = 1;
		}
		else {							//lúc bình thường
			startX = 0;
			endX = widthObj;
			idx = mX + 1;
		}

		//In ra màn hình đối tượng đó 
		for (int i = 0; i < heightObj; i++) {
			CONSOLE::gotoXY(idx, mY + i);

			for (int j = startX; j < endX; j++)
				cout << obj_1[i][j];

			if (mX + widthObj + 1 < sRIGHT)
				cout << " ";					//xóa vết nếu nó không chạm biên phải
		}

		break;
	}
	}
}