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
void CDRAW::drawHorizontalLine(COORD coord, SHORT width, SHORT typeChar, SHORT textColor) {
	CONSOLE::textcolor(textColor);
	CONSOLE::gotoXY(coord.X, coord.Y);
	for (short ix = 0; ix != width; ix++)
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
void CDRAW::drawVerticalLine(COORD coord, SHORT height, SHORT typeChar, SHORT textColor) {
	CONSOLE::textcolor(textColor);
	for (short iy = 0; iy != height; iy++) {
		CONSOLE::gotoXY(coord.X, coord.Y + iy);
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
void CDRAW::drawBox(COORD coord, SHORT width, SHORT height, SHORT horizo, SHORT vertical,
	SHORT topLeft, SHORT topRight, SHORT botLeft, SHORT botRight, SHORT textColor) {

	short y_bottom = coord.Y + height;
	short x_right = coord.X + width;
	drawHorizontalLine(coord, width, horizo, textColor);
	drawHorizontalLine(COORD{ coord.X, y_bottom}, width, horizo, textColor);

	drawVerticalLine(COORD{ coord.X, coord.Y }, height, vertical, textColor);
	drawVerticalLine(COORD{ x_right, coord.Y }, height, vertical, textColor);

	CONSOLE::gotoXY(coord.X, coord.Y);
	cout << char(topLeft);
	CONSOLE::gotoXY(coord.X + width, coord.Y);
	cout << char(topRight);
	CONSOLE::gotoXY(coord.X, coord.Y + height);
	cout << char(botLeft);
	CONSOLE::gotoXY(coord.X + width, coord.Y + height);
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
void CDRAW::drawGameName(string filename, COORD coord, SHORT color, int delay) {
	ifstream fin(filename);
	if (fin.fail())
		return;

	string line;
	short y_pointer = coord.Y;
	while (!fin.eof()) {
		getline(fin, line);
		CONSOLE::gotoXY(coord.X, y_pointer++);
		CONSOLE::textcolor(color);
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
void CDRAW::backroundBox(COORD coord, SHORT width, SHORT height, SHORT backgroudColor) {
	string line;
	CONSOLE::textcolor(backgroudColor);

	for (short i = 0; i < width; i++)
		line += " ";
	for (short i = coord.Y; i < coord.Y + height; i++) {
		CONSOLE::gotoXY(coord.X, i);
		cout << line;
	}
}

void CDRAW::printString(string content, COORD coord, SHORT color, SHORT width) {
	CONSOLE::textcolor(color);
	if (width == 0) {
		CONSOLE::gotoXY(coord.X, coord.Y);
		cout << content;
		return;
	}
	int new_x = (coord.X + width - content.length()) / 2;
	CONSOLE::gotoXY(new_x, coord.Y);
	cout << content;
}