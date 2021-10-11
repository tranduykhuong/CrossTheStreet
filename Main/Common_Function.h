#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void FixConsoleWindow();
void SetWindowSize(SHORT, SHORT);
void SreenConsole_Top_Left();
void HiddenScrollBar();
void gotoXY(int, int);
void ShowCur(bool CursorVisibility);
void textcolor(int x);