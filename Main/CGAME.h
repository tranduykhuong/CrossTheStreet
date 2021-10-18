#pragma once
#include"Common_Function.h"
#include"CDRAW.h"
#include"CMENU.h"

#define SCREEN_GAME_WIDTH 100
#define SCREEN_GAME_HEIGHT 40
#define SCREEN_GAME_RECT_X 0
#define SCREEN_GAME_RECT_Y 0
#define NUMBER_ROAD 8

#define BACKGROUND_GAME_COLOR 7
#define TEXT_BOX_GAME_COLOR 112

class CGAME {
private:

public:
	CGAME() {};

	void runApp();
	void drawGame();
	void drawGuide();
};