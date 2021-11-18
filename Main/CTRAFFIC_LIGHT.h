#pragma once
#include "CONSOLE.h"

class CTRAFFIC_LIGHT
{
private:
	int mX;
	int mY;
	int mColor = 1;		//1 is xanh mau nay, 0 la do
	int mSleep = 30;
public:
	int getLightColor();
	int getLightSleep();
	void setLightX(int);
	void setLightY(int);
	void setLightColor(int color);
	void setLightSleep(int sleep);
	void setLight(int color);
	void drawLight(int mX, int mY);
};