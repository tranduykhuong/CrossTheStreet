#include"CMENU.h"
#include<string>

CMENU::CMENU(COORD coord, SHORT width, bool sound) {
	this->coord = coord;
	this->y_ptr = coord.Y;
	this->width = width;
	this->height = 2;
	this->boxColor = BOX_COLOR;
	this->charColor = CHAR_COLOR;
	this->titleColor = 31;
	this->isSound = sound;
}

CMENU::~CMENU() {
	this->coord = { 0,0 };
	this->y_ptr = 0;
	this->height = 0;
	this->width = 0; 
}

// SET COORDINATE AND WIDTH OF TABLE
void CMENU::setPosition_Width(COORD coord, SHORT width) {
	this->coord = coord;
	this->y_ptr = coord.Y;
	this->width = width;
}

// FUNCTON TO DRAW CORNERS AMONG OF BOX (EXCEPT CORNERS OF TABLE)
void CMENU::cornerAmongBox(SHORT y_cur) {
	CONSOLE::textcolor(boxColor);
	CONSOLE::gotoXY(coord.X, y_cur);			//right corner
	cout << char(195);
	CONSOLE::gotoXY(coord.X + width, y_cur);	//left corner
	cout << char(180);
}

// ADD AN ITEM
void CMENU::addItem(string ops) {
	opsArr.push_back(ops);
}

// REMOVE AN ITEM AT AN INDEX
bool CMENU::removeItem(int idx) {
	if (idx >= opsArr.size() || idx < 0)
		return false;
	opsArr.erase(opsArr.begin() + idx);
	return true;
}

// INSERT AN ITEM AT AN INDEX
void CMENU::insertItem(string content, int idx) {
	opsArr.insert(opsArr.begin() + idx, content);
}

// DRAWING BACKGROUND AND CONTENT OF AN OPTION (ITEM)
void CMENU::dataBox(COORD coord_data, string content, SHORT newColor) {
	short textColor = this->charColor;
	if (newColor != -1)
		textColor = newColor;

	short x_box = coord_data.X + 1;
	short y_box = coord_data.Y + 1;
	CDRAW::clearBox(COORD{ x_box, y_box }, textColor, width - 1, height - 1);

	CONSOLE::textcolor(textColor);
	CONSOLE::gotoXY(coord_data.X + 1 + (width - content.length()) / 2, coord_data.Y + height / 2);	// print a string at center of box
	cout << content;
}

// DRAWING BACKGROUND AND CONTENT OF A LOGICAL OPTION
void CMENU::dataBoxTrueFalse(COORD coord_data, string& content, bool& set, SHORT opsColor, SHORT newColor) {
	short textColor = this->charColor;
	if (newColor != -1)
		textColor = newColor;
	if (opsColor == -1)
		opsColor = textColor;

	short x_box = coord_data.X + 1;
	short y_box = coord_data.Y + 1;
	CDRAW::clearBox(COORD{ x_box, y_box }, textColor, width - 1, height - 1);

	CONSOLE::gotoXY(coord_data.X + 3, coord_data.Y + height / 2);
	CONSOLE::textcolor(textColor);
	cout << content;

	CONSOLE::gotoXY(coord_data.X + width - 8, coord_data.Y + height / 2);
	cout << char(174);
	CONSOLE::textcolor(opsColor);
	if (set)	cout << " YES ";
	else cout << " NO  ";
	CONSOLE::textcolor(textColor);
	cout << char(175);
}

// SET COLOR FOR TABLE
void CMENU::setColorTable(SHORT boxColor, SHORT charColor) {
	this->boxColor = boxColor;
	this->charColor = charColor;
}

// SET COLOR OF TITLE TABLE NONE LINE
void CMENU::setColorTitle(SHORT newColor)
{
	if (newColor > 0)
		titleColor = newColor;
}


// DISPLAY OPTIONAL TABLE 
void CMENU::displayTableLine() {
	short tempY = coord.Y;
	for (auto e : opsArr) {
		CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
		dataBox(COORD{ coord.X, tempY }, e);
		if (tempY != coord.Y)
			cornerAmongBox(tempY);
		tempY += height;
	}
}

// DISPLAY MENU NONE LINE
void CMENU::displayTableNoneLine() {
	short tempY = coord.Y;
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, opsArr.size() +  1, 223, 219, 219, 219, 223, 223, boxColor);
	dataBox(COORD{ coord.X, tempY++ }, opsArr[0], titleColor); // vẽ title

	for (int i = 1; i < opsArr.size(); i++) {
		dataBox(COORD{ coord.X, tempY }, opsArr[i]);
		//tempY += height;
		tempY++;
	}
}

// GET SELECT FROM USER
int CMENU::getSelectFromUser() {
	displayTableLine();
	
	short optionColor = OPTION_COLOR;
	int index = 0;
	int sizeOps = opsArr.size();
	
	dataBox(COORD{ coord.X, y_ptr }, opsArr[index], optionColor);		//hàm tạo màu khác cho option

	while (true) {		//sử dụng 2 phím (lên, xuống) để điều kiển
		char c = toupper(_getch());
		CONSOLE::releaseChar();
		if (c == 13) {		//khi nhập enter sẽ kết thúc while
			if (isSound)
				PlaySound(TEXT("OST/menu click.wav"), NULL, SND_ASYNC);
			return index;
		}
		else {
			if (c == 'S') {	//đi xuống
				dataBox(COORD{ coord.X, y_ptr }, opsArr[index]);			//vẽ chồng màu lên option
				if (index < sizeOps - 1) {
					y_ptr += height;
					index++;
				}
				else {
					y_ptr = coord.Y;
					index = 0;
				}
				dataBox(COORD{ coord.X, y_ptr }, opsArr[index], optionColor);		//vẽ lại option mới
				if (isSound)
					PlaySound(TEXT("OST/menu move.wav"), NULL, SND_ASYNC);
			}
			else if (c == 'W') { //đi lên
				dataBox(COORD{ coord.X, y_ptr }, opsArr[index]);		//vẽ chồng màu lên option
				if (index > 0) {
					y_ptr -= height;
					index--;
				}
				else {
					y_ptr = coord.Y + (sizeOps - 1) * height;
					index = sizeOps - 1;
				}
				dataBox(COORD{ coord.X, y_ptr }, opsArr[index], optionColor);		//vẽ lại option mới
				if (isSound)
					PlaySound(TEXT("OST/menu move.wav"), NULL, SND_ASYNC);
			}
		}

	}
}

// GET INPUT STRING FROM USER
string CMENU::getInputString()
{
	short tempY = coord.Y;
	string str;

	// Title
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
	dataBox(COORD{ coord.X, tempY }, opsArr[0], titleColor);
	tempY += height;

	// Header
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
	dataBox(COORD{ coord.X, tempY }, opsArr[1], 113);
	cornerAmongBox(tempY);
	tempY += height;

	// input
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
	dataBox(COORD{ coord.X, tempY }, "", 113);
	cornerAmongBox(tempY);
	CONSOLE::gotoXY(coord.X + 5, tempY + 1);
	CONSOLE::ShowCur(true);
	getline(cin, str);
	CONSOLE::ShowCur(false);

	return str;
}

int CMENU::getSizeOpsArr()
{
	return opsArr.size();
}

// GET SETTING OPTIONS (2 PARAMETERS) FROM USER
void CMENU::getSettingFromUser(bool& a1, bool& a2) {
	short tempY = coord.Y;

	// Item 1
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
	dataBoxTrueFalse(COORD{ coord.X, tempY }, opsArr[0], a1);
	tempY += height;

	// Item 2
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
	dataBoxTrueFalse(COORD{ coord.X, tempY }, opsArr[1], a2);
	cornerAmongBox(tempY);
	tempY += height;

	// Apply
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
	dataBox(COORD{ coord.X, tempY }, opsArr[2], 62);
	cornerAmongBox(tempY);

	//tạo màu cho ô được chọn
	short optionColor = 164;

	dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[0], a1, optionColor); //hàm tạo màu khác cho option

	while (true) {			//sử dụng 2 phím (lên, xuống) để điều kiển
		char c = toupper(_getch());
		CONSOLE::releaseChar();

		if (c == 13 && y_ptr == coord.Y + height * 2) {		//khi nhập enter sẽ kết thúc while
			if (isSound)
				PlaySound(TEXT("OST/menu click.wav"), NULL, SND_ASYNC);
			this->isSound = a1;
			return;
		}
		else {
			if (c == 'S') {	//đi xuống
				if (y_ptr == coord.Y) {
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[0], a1);
					y_ptr += height;
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[1], a2, optionColor);
				}
				else if (y_ptr == coord.Y + height) {
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[1], a2);
					y_ptr += height;
					dataBox(COORD{ coord.X, y_ptr }, opsArr[2], optionColor);
				}
			}
			else if (c == 'W') { //đi lên
				if (y_ptr == coord.Y + height) {
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[1], a2);
					y_ptr -= height;
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[0], a1, optionColor);
				}
				else if (y_ptr == coord.Y + height * 2) {
					dataBox(COORD{ coord.X, y_ptr }, opsArr[2], 62);
					y_ptr -= height;
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[1], a2, optionColor);
				}
			}

			// Setting True/False
			if (c == 'A' || c == 'D') {
				if (y_ptr == coord.Y) {
					a1 = !a1;
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[0], a1, optionColor);
				}
				else if (y_ptr == coord.Y + height) {
					a2 = !a2;
					dataBoxTrueFalse(COORD{ coord.X, y_ptr }, opsArr[1], a2, optionColor);
				}
			}
			if (isSound)
				PlaySound(TEXT("OST/menu move.wav"), NULL, SND_ASYNC);
		}
	}
}