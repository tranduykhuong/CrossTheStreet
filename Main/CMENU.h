#pragma once
#include"CDRAW.h"

#define BOX_COLOR 123
#define CHAR_COLOR 224

class CMENU {
	int x, y;
	int y_ptr;
	int width, height;
	int boxColor, charColor;
	vector<string> opsArr;

	CDRAW draw;

	void cornerAmongBox(int y_cur);
	void dataBox(int x_data, int y_data, string& content, int newColor = -1);
public:

	CMENU(int x, int y, int width);
	~CMENU();

	void setColorBox(int boxColor, int charColor);
	void setPosition_Width(int x, int y, int width);
	void addOption(string ops);
	void displayTable();
	int getSelectFromUser();
};