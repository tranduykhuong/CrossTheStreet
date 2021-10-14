#pragma once
#include"Common_Function.h"


class CDRAW {
private:

public:
	static void drawHorizontalLine(COORD, SHORT, SHORT, SHORT);
	static void drawVerticalLine(COORD, SHORT, SHORT, SHORT);
	static void drawBox(COORD, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT);
	static void backroundBox(COORD, SHORT, SHORT, SHORT);
	static void drawGameName(string, COORD, SHORT, int);
	static void printString(string, COORD, SHORT color = 0, SHORT width = 0);
};