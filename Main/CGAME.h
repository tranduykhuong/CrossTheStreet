#pragma once
#include"Common_Function.h"
#include"CDRAW.h"
#include"CMENU.h"

#define SCREEN_CONSOLE_WIDTH 146
#define SCREEN_CONSOLE_HEIGHT 40

#define SCREEN_GAME_WIDTH 90
#define SCREEN_GAME_HEIGHT 40
#define SCREEN_GAME_RECT_X 0
#define SCREEN_GAME_RECT_Y 0
#define NUMBER_ROAD 8

class CGAME {
private:
	CDRAW cdraw;
	CMENU cmenu = CMENU((SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 2, 30);

public:
	CGAME() {};

	void drawGame();
	void drawMenuGame();
};