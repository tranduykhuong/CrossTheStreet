#include "CTRAFFIC_LIGHT.h"

short CTRAFFIC_LIGHT::getLightColor()
{
	return this->mColor;
}

CTRAFFIC_LIGHT::CTRAFFIC_LIGHT()
{
	mColor = 1;
}

void CTRAFFIC_LIGHT::setLightX(short X) {
	this->mX = X;
}

void CTRAFFIC_LIGHT::setLightY(short Y) {
	this->mY = Y;
}

void CTRAFFIC_LIGHT::setLightColor(short color)
{
	this->mColor = color;
}

void CTRAFFIC_LIGHT::drawLight(short mX, short mY) {
	if (this->mColor == 1) // mau xanh
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