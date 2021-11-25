#pragma once
#include"CONSOLE.h"


class CDRAW {
private:

public:
	static void drawHorizontalLine(COORD, SHORT, SHORT, SHORT);
	static void drawVerticalLine(COORD, SHORT, SHORT, SHORT);
	static void drawBox(COORD, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT);
	static void backroundBox(COORD, SHORT, SHORT, SHORT);
	static void drawGameTXT(string, COORD, SHORT, int);
	static void clearBox(COORD, SHORT, SHORT, SHORT);

	static void drawLogo(COORD, SHORT speed, SHORT delay, bool);
	static void DrawLogo(string, COORD, SHORT speed, SHORT delay, SHORT color, bool isSound);
	static void drawTitle(COORD, SHORT color, bool);
	static void drawGameOverScreen(COORD, SHORT color, bool);
	static void drawLevelCompleteScreen(COORD, SHORT color, bool);
};