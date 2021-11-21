#include "CANIMAL.h"

CANIMAL::CANIMAL()
{
	mY = mX = mSpeed = 0;
	mColor = ColorGame::black;
	mMove = LEFT;
}

CANIMAL::CANIMAL(const CANIMAL& an)
{
	mX = an.mX;
	mY = an.mY;
	mColor = an.mColor;
	mSpeed = an.mSpeed;
	mMove = an.mMove;
}

CANIMAL::CANIMAL(const short& x, const short& y, const short& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
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

void CANIMAL::setColor(const short& color)
{
	mColor = color;
}

void CANIMAL::setMove(const short& _move)
{
	mMove = _move;
}

void CANIMAL::setSpeed(const short& speed)
{
	mSpeed = speed;
}

short CANIMAL::getX() const
{
	return mX;
}

short CANIMAL::getY() const
{
	return mY;
}

short CANIMAL::getColor() const
{
	return mColor;
}

short CANIMAL::getSpeed() const
{
	return mSpeed;
}

short CANIMAL::getMove() const
{
	return mMove;
}

//move : Hướng di chuyển của đối tượng 
void CANIMAL::drawAnimal(const vector<vector<short>>& obj, const short& move) const
{
	CONSOLE::textcolor(mColor);
	short heightObj = obj.size();			//chiều cao của đối tượng
	short widthObj = obj[0].size();			//chiều dài của đối tượng 
	short startX, endX, idx;				//Index đầu - cuối của obj, vị trí in trên màn hình 

	if (mX < sLEFT + 1) {					//xử lý biên trái
		startX = sLEFT - mX + 1;
		endX = widthObj;
		idx = sLEFT + 1;
	}
	else if (mX + widthObj > sRIGHT) {		//xử lý biên phải
		startX = 0;
		endX = sRIGHT - mX;
		idx = mX;
	}
	else {									//lúc bình thường
		startX = 0;
		endX = widthObj;
		idx = mX;
	}

	//In ra màn hình đối tượng đó 
	switch (move) {
	case Key::RIGHT:

		for (int i = 0; i < heightObj; i++) {

			if (idx > sLEFT + 1) {					//xóa vết nếu nó không chạm biên trái
				CONSOLE::gotoXY(idx - 1, mY + i);
				cout << " ";
			}
			else CONSOLE::gotoXY(idx, mY + i);


			for (int j = startX; j < endX; j++)		//In theo hàng ngang
				cout << char(obj[i][j]);
		}
		break;

	case Key::LEFT:

		for (int i = 0; i < heightObj; i++) {

			if (idx < sRIGHT - widthObj) {					//Xóa vết nếu đuôi đối tượng không cham biên phải
				CONSOLE::gotoXY(mX + widthObj, mY + i);
				cout << " ";
			}

			CONSOLE::gotoXY(idx, mY + i);					//Đưa đến vị trí xuất đối tượng

			for (int j = startX; j < endX; j++)				//In theo hàng ngang
				cout << char(obj[i][j]);
		}
		break;

	}
}