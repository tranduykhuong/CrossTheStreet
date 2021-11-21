#pragma once
#include"CDRAW.h"

#define BOX_COLOR 121
#define CHAR_COLOR 224
#define OPTION_COLOR 206

class CMENU {
	COORD coord;
	SHORT y_ptr;
	SHORT width, height;
	SHORT boxColor, charColor;
	vector<string> opsArr;

	bool isSound;

	void cornerAmongBox(SHORT y_cur);
	void dataBox(COORD coord_data, string& content, SHORT newColor = -1);
	void dataBoxTrueFalse(COORD coord_data, string& content, bool& set, SHORT opsColor = -1, SHORT newColor = -1);
public:

	CMENU(COORD, SHORT width, bool sound = true);
	~CMENU();

	void setColorTable(SHORT boxColor, SHORT charColor);
	void setPosition_Width(COORD, SHORT width);
	void addItem(string ops);
	void displayTableLine();
	void displayTableNoneLine();
	bool removeItem(int);
	void insertItem(string, int);
	
	void getSettingFromUser(bool& a1, bool& a2);
	int getSelectFromUser();
};