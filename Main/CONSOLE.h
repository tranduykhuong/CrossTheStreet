#pragma once
#include<Windows.h>

class CONSOLE
{
private:

public:
	static void FixConsoleWindow();
	static void SetWindowSize(SHORT, SHORT);
	static void SreenConsole_Top_Left();
	static void HiddenScrollBar();
	static void ShowCur(bool CursorVisibility);
	static void gotoXY(int, int);
	static void textcolor(int x);
};

