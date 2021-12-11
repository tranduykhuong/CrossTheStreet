#pragma once
#include "CONSOLE.h"

class CTRAFFIC_LIGHT
{
private:
	short mX;
	short mY;
	short mColor;		// 1 is xanh mau nay, 0 la do

public:
	CTRAFFIC_LIGHT();
	short getLightColor();
	void setLightX(short);
	void setLightY(short);
	void setLightColor(short color);
	void drawLight(short mX, short mY);
};