#pragma once
#include"CDRAW.h"

#define BOX_COLOR 123
#define CHAR_COLOR 224

class CMENU {
	COORD coord;
	SHORT y_ptr;
	SHORT width, height;
	SHORT boxColor, charColor;
	vector<string> opsArr;

	void cornerAmongBox(SHORT y_cur);
	void dataBox(COORD coord_data, string& content, SHORT newColor = -1);
public:

	CMENU(COORD, SHORT width);
	~CMENU();

	void setColorTable(SHORT boxColor, SHORT charColor);
	void setPosition_Width(COORD, SHORT width);
	void addItem(string ops);
	void displayTableLine();
	void displayTableNoneLine();
	bool removeItem(int);
	void insertItem(string, int);
	
	int getSelectFromUser();
};