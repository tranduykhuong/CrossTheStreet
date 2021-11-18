#include "CTRAFFIC_LIGHT.h"

int CTRAFFIC_LIGHT::getLightColor()
{
	return this->mColor;
}
int CTRAFFIC_LIGHT::getLightSleep()
{
	return this->mSleep;
}

void CTRAFFIC_LIGHT::setLightX(int X) {
	this->mX = X;
}
void CTRAFFIC_LIGHT::setLightY(int Y) {
	this->mY = Y;
}
void CTRAFFIC_LIGHT::setLightColor(int color)
{
	this->mColor = color;
}
void CTRAFFIC_LIGHT::setLightSleep(int sleep)
{
	this->mSleep = sleep;
}
void CTRAFFIC_LIGHT::setLight(int color)
{
	this->mColor = color;
	//this->mSleep = sleep;
}
void CTRAFFIC_LIGHT::drawLight(int mX, int mY) {
	if (this->mColor == 1) // màu xanh
	{
		CONSOLE::textcolor(ColorGame::black);
		CONSOLE::gotoXY(mX + 1, mY + 1);
		cout << char(219);
		CONSOLE::textcolor(ColorGame::black);
		CONSOLE::gotoXY(mX + 2, mY + 1);
		cout << char(219);
		CONSOLE::textcolor(ColorGame::green);
		CONSOLE::gotoXY(mX + 2, mY);
		cout << char(219);
		CONSOLE::textcolor(ColorGame::green);
		CONSOLE::gotoXY(mX + 1, mY);
		cout << char(219);
	}
	else {
		CONSOLE::textcolor(ColorGame::black);
		CONSOLE::gotoXY(mX + 2, mY);
		cout << char(219);
		CONSOLE::textcolor(ColorGame::black);
		CONSOLE::gotoXY(mX + 1, mY);
		cout << char(219);
		CONSOLE::textcolor(ColorGame::red);
		CONSOLE::gotoXY(mX + 1, mY + 1);
		cout << char(219);
		CONSOLE::textcolor(ColorGame::red);
		CONSOLE::gotoXY(mX + 2, mY + 1);
		cout << char(219);
	}
}