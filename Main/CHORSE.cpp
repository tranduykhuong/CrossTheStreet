#include "CHORSE.h"

CHORSE::CHORSE() {
	mMove = LEFT;
}

CHORSE::~CHORSE() {
	mX = 0;
	mY = 0;
	mColor = 0;
	mSpeed = 0;
	mMove = 0;
}

void CHORSE::set(const short& x, const short& y, const int& color, const short& speed, const short& move) {
	mX = x;
	mY = y;
	mColor = color;
	mSpeed = speed;
	mMove = move;
}

int CHORSE::getHeight() {
	return horseLeft_1.size();
}

int CHORSE::getWidth() {
	return horseLeft_1[0].size();
}

void CHORSE::tell() {
	PlaySound(TEXT("VoiceHorse.wav"), NULL, SND_SYNC);
}

void CHORSE::move() {
	if (mMove == RIGHT) {

		short type = 0;			//Khóa xác định kiểu di chuyển của con thỏ
		while (true)
		{

			if (type % 2 == 0)
				CANIMAL::drawAnimal(horseRight_1, mMove);
			else
				CANIMAL::drawAnimal(horseRight_2, mMove);
			mX++, type++;

			//nếu xe chạm biên phải thì cho xuất phát lại
			if (mX == sRIGHT)
				setX((getWidth() * (-1)));

			Sleep(mSpeed);
		}
	}
	else {

		short type = 0;			//Khóa xác định kiểu di chuyển của con thỏ
		while (true)
		{
			if (type % 2 == 0)
				CANIMAL::drawAnimal(horseLeft_1, mMove);
			else
				CANIMAL::drawAnimal(horseLeft_2, mMove);
			mX--, type++;

			//nếu xe chạm biên trái thì cho xuất phát lại
			if (mX == sLEFT - getWidth() - 1)
				setX(sRIGHT);

			Sleep(mSpeed);
		}
	}
}