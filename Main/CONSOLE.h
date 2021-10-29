#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

// Information of Window size and Screen Buffer size 
#define WINDOW_WIDTH 1200		 //pixel
#define WINDOW_HEIGHT 695		 //pixel
#define SCREEN_CONSOLE_WIDTH 146 //number of column
#define SCREEN_CONSOLE_HEIGHT 40 //number of row

// Information of game screen
#define SCREEN_GAME_WIDTH 110 //number of column
#define SCREEN_GAME_HEIGHT 40 //number of row
#define SCREEN_GAME_RECT_X 0
#define SCREEN_GAME_RECT_Y 0
#define NUMBER_ROAD 8

#define BACKGROUND_GAME_COLOR 7

// Border coordinates of the game screen
enum GameScreen {
	sLEFT   = SCREEN_GAME_RECT_X,
	sRIGHT  = SCREEN_GAME_RECT_X + SCREEN_GAME_WIDTH,
	sTOP    = SCREEN_GAME_RECT_Y,
	sBOTTOM = SCREEN_GAME_RECT_Y + SCREEN_GAME_HEIGHT
};

enum ColorGame {
	black	= 112,
	blue	= 113,
	green	= 114,
	teal	= 115,
	maroon	= 116,
	purple	= 117,
	olive	= 118,
	silver	= 119,
	grey	= 120,
	navi	= 121,
	lime	= 122,
	aqua	= 123,
	red		= 124,
	pink	= 125,
	yellow	= 126,
	white	= 127
};

enum Key {
	UP = 87,	//W
	DOWN = 83,	//S
	LEFT = 65,  //A
	RIGHT = 68	//D
};

class CONSOLE
{
private:

public:
	static void FixConsoleWindow();
	static void SetWindowSize(SHORT, SHORT);
	static void SetConsoleOutput(int);
	static void SetTitleCosole(LPCSTR);
	static void SreenConsole_Top_Left();
	static void HiddenScrollBar();
	static void ShowCur(bool CursorVisibility);
	static void gotoXY(int, int);
	static void textcolor(int x);
};

