#pragma once
#pragma execution_character_set("utf-8")
#include<iostream>
#include<thread>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

using namespace std;

// Information of Window size and Screen Buffer size 
#define WINDOW_WIDTH 1210		 //pixel
#define WINDOW_HEIGHT 695		 //pixel
#define SCREEN_CONSOLE_WIDTH 146 //number of column
#define SCREEN_CONSOLE_HEIGHT 40 //number of row

// Information of game screen
#define SCREEN_GAME_WIDTH 110 //number of column
#define SCREEN_GAME_HEIGHT 40 //number of row
#define SCREEN_GAME_RECT_X 4
#define SCREEN_GAME_RECT_Y 0
#define HEIGHT_ROAD 5

#define BACKGROUND_GAME_COLOR 7
// Border coordinates of the game screen
enum GameScreen {
	sLEFT   = SCREEN_GAME_RECT_X,
	sRIGHT  = SCREEN_GAME_RECT_X + SCREEN_GAME_WIDTH,
	sTOP    = SCREEN_GAME_RECT_Y,
	sBOTTOM = SCREEN_GAME_RECT_Y + SCREEN_GAME_HEIGHT
};

enum ColorGame {
	black	= 224,
	blue	= 225,
	green	= 226,
	teal	= 227,
	maroon	= 228,
	purple	= 229,
	olive	= 230,
	silver	= 231,
	grey	= 232,
	navi	= 233,
	lime	= 234,
	aqua	= 235,
	red		= 236,
	pink	= 237,
	yellow	= 238,
	white	= 239
};

enum Key {
	UP = 87,	//W
	DOWN = 83,	//S
	LEFT = 65,  //A
	RIGHT = 68	//D
};

class CONSOLE
{
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
	static int getConsoleCharacter(const int&, const int&);
};

