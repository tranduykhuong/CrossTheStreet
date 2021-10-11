#pragma once
#include"Common_Function.h"

class CDRAW {
public:
	void drawHorizontalLine(int x, int y, int width, int typeChar, int textColor);
	void drawVerticalLine(int x, int y, int width, int typeChar, int textColor);
	void drawBox(int x, int y, int width, int height, int horizo, int vertical,
		int topLeft, int topRight, int botLeft, int botRight, int textColor);
	void drawGameName(string filename, int x, int y, int color, int delay);
	void backroundBox(int x, int y, int width, int hight, int& charColor);
	void printString(string content, int x, int y, int color = 0, int width = 0);
};