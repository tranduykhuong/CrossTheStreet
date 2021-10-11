#include"CDRAW.h"


/***********************************************************
* FUNCTION TO DRAW HORIZONTAL LINE
* Parameters:
*	x			: x coordinate of the left end of the line
*	y			: y coordinate of the left end of the line
*	width		: length of the line
*	typeChar	: character type for drawing the line
*	textColor	: the color of the character
************************************************************/
void CDRAW::drawHorizontalLine(int x, int y, int width, int typeChar, int textColor) {
	textcolor(textColor);
	gotoXY(x, y);
	for (int ix = 0; ix != width; ix++)
		cout << char(typeChar);
}


/***********************************************************
* FUNCTION TO DRAW VERTICAL LINE
* Parameters:
*	x			: x coordinate of the left end of the line
*	y			: y coordinate of the left end of the line
*	height		: height of the line
*	typeChar	: character type for drawing the line
*	textColor	: the color of the character
************************************************************/
void CDRAW::drawVerticalLine(int x, int y, int height, int typeChar, int textColor) {
	textcolor(textColor);
	for (int iy = 0; iy != height; iy++) {
		gotoXY(x, y + iy);
		cout << char(typeChar);
	}
}


/****************************************************************
* FUNCTION THAT DRAWING A BOX
* Parameters:
*	x			: x-coordinate of the upper left corner of the box
*	y			: y-coordinate of the upper left corner of the box
*	width		: width of box
*	height		: heigth of box
*	horizo		: character type for horizontal line
*	vertical	: character type for vertical line
*	topLeft		: character type for top left corner
*	topRight	: character type for top right corner
*	botLeft		: character type for bottom left corner
*	botRight	: character type for bottom right corner
*   textColor	: the color of the character
******************************************************************/
void CDRAW::drawBox(int x, int y, int width, int height, int horizo, int vertical,
	int topLeft, int topRight, int botLeft, int botRight, int textColor) {

	drawHorizontalLine(x, y, width, horizo, textColor);
	drawHorizontalLine(x, y + height, width, horizo, textColor);

	drawVerticalLine(x, y, height, vertical, textColor);
	drawVerticalLine(x + width, y, height, vertical, textColor);

	gotoXY(x, y);
	cout << char(topLeft);
	gotoXY(x + width, y);
	cout << char(topRight);
	gotoXY(x, y + height);
	cout << char(botLeft);
	gotoXY(x + width, y + height);
	cout << char(botRight);
}

/***************************************************************
* FUNCTION TO DRAW NAME OF THE GAME
* Parameters:
*	filename	: name of file txt
*	x			: x-coordinate of the upper left corner of name
*	y			: y-coordinate of the upper left corner of name
*   textColor	: the color of the character
*	delay		: delay while printing each line	
****************************************************************/
void CDRAW::drawGameName(string filename, int x, int y, int color, int delay) {
	ifstream fin(filename);
	if (fin.fail())
		return;

	string line;
	int y_pointer = y;
	while (!fin.eof()) {
		getline(fin, line);
		gotoXY(x, y_pointer++);
		textcolor(color);
		cout << line << endl;
		Sleep(delay);
	}
	fin.close();
}


/*********************************************************
* FUNCTION TO DRAW BACKGROUND COLOR FOR BOX
* Parameters:
*	x			: x-coordinate of the upper left corner of box
*	y			: y-coordinate of the upper left corner of box
*	width		: width of box
*	height		: heigth of box
*	backgroudColor: color of background
**********************************************************/
void CDRAW::backroundBox(int x, int y, int width, int height, int& backgroudColor) {
	string line;
	textcolor(backgroudColor);

	for (int i = 0; i < width; i++)
		line += " ";
	for (int i = y; i < y + height; i++) {
		gotoXY(x, i);
		cout << line;
	}
}

void CDRAW::printString(string content, int x, int y, int color, int width) {
	textcolor(color);
	if (width == 0) {
		gotoXY(x, y);
		cout << content;
		return;
	}
	int new_x = (x + width - content.length()) / 2;
	gotoXY(new_x, y);
	cout << content;
}