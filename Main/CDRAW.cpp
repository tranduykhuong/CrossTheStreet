#include"CDRAW.h"


/***********************************************************
* FUNCTION TO DRAW HORIZONTAL LINE
* Parameters:
*	coord		: coordinates of the left end
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
*	coord		: coordinates of the left end
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
*	coord		: coordinates of the left end
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
	drawHorizontalLine(COORD{ coord.X, y_bottom }, width, horizo, textColor);

	drawVerticalLine(COORD{ coord.X, coord.Y }, height, vertical, textColor);
	drawVerticalLine(COORD{ x_right, coord.Y }, height, vertical, textColor);

	CONSOLE::textcolor(textColor);
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
*	coord		: coordinates of the left end
*   textColor	: the color of the character
*	delay		: delay while printing each line
****************************************************************/
void CDRAW::drawGameTXT(string filename, COORD coord, SHORT color, int delay) {
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
*	coord		: coordinates of the left end
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

/*********************************************************
* FUNCTION TO CLEAR A BOX
* Parameters:
*	coord		: coordinates of the left end
*	width		: width of box
*	height		: heigth of box
*	color		: color of background
**********************************************************/
void CDRAW::clearBox(COORD coord, SHORT color, SHORT width, SHORT height) {
	CONSOLE::textcolor(color);
	
	CONSOLE::gotoXY(coord.X, coord.Y);
	string w = "";
	for (int i = 0; i < width; i++)
		w += ' ';
	for (int i = 0; i < height; i++) {
		CONSOLE::gotoXY(coord.X, coord.Y + i);
		cout << w;
	}
}


/*******************************************************************
* Hàm vẽ logo (bổ trợ cho hàm drawLogo ở dưới)
* Các tham số:
*    fiName		: Tên file đầu vào.
*    coord		: Tọa độ.
*    speed		: Tốc độ vẽ, tốc độ xóa.
*    delay		: Thời gian tồn tại trước khi bị xóa.
*    color		: Màu sắc.
*    isSound	: Âm thanh.
*********************************************************************/
void CDRAW::DrawLogo(string fiName, COORD coord, SHORT speed, SHORT delay, SHORT color, bool isSound) {
	ifstream fi(fiName);
	if (fi.fail()) return;

	// Vẽ logo:
	string s;
	CONSOLE::textcolor(color);

	if (isSound) PlaySound(TEXT("OST/Wind-Shoowsh-Fast-www.fesliyanstudios.com.wav"), NULL, SND_ASYNC);
	short charType = 219;
	drawBox(COORD{ 1,1 }, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2,
		charType, charType, charType, charType, charType, charType, 11);

	for (int i = 0; !fi.eof(); i++) {
		getline(fi, s);
		CONSOLE::gotoXY(coord.X, coord.Y + i);
		cout << s;
		Sleep(speed);
	}

	Sleep(delay);

	// Xóa logo:
	fi.seekg(0, ios::beg);
	CONSOLE::textcolor(0);

	if (isSound) PlaySound(TEXT("OST/mixkit-arrow-whoosh-1491.wav"), NULL, SND_ASYNC);
	for (int i = 0; !fi.eof(); i++) {
		getline(fi, s);
		CONSOLE::gotoXY(coord.X, coord.Y + i);
		cout << s;
		Sleep(speed);
	}

	Sleep(delay);
	system("cls");
	fi.close();
}
/*******************************************************************
* Hàm vẽ logo HCMUS và team5
* coord		: Tọa độ.
* speed		: Tốc độ vẽ, tốc độ xóa.
* delay		: Thời gian tồn tại trước khi bị xóa của mỗi logo.
* isSound	: Âm thanh.
********************************************************************/
void CDRAW::drawLogo(COORD coord, SHORT speed, SHORT delay, bool isSound) {
	system("color 0e");
	
	DrawLogo("Text/HCMUS.txt", coord, speed, delay, 1, isSound);
	DrawLogo("Text/Team5.txt", coord, speed, delay, 3, isSound);
}


/******************************************************************
* Hàm vẽ title game
* Các tham số:
* coord		: Tọa độ.
* color		: Màu sắc.
* isSound	: Âm thanh.
*******************************************************************/
void CDRAW::drawTitle(COORD coord, SHORT color, bool isSound) {
	if (isSound) {
		mciSendString(TEXT("open \"OST/title.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
		mciSendString(TEXT("play mp3 repeat"), NULL, 0, NULL);
	}

	ifstream fi("Text/Title.txt");

	if (fi.fail()) return;
	short charType = 219;
	drawBox(COORD{ 1,1 }, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2,
		charType, charType, charType, charType, charType, charType, 11);

	int x, y;
	CONSOLE::textcolor(color);

	if (isSound) PlaySound(TEXT("OST/Writing.wav"), NULL, SND_ASYNC);

	while (!fi.eof()) {
		fi >> x >> y;
		CONSOLE::gotoXY(coord.X + x, coord.Y + y);
		cout << char(254);
		Sleep(12);
	}

	for (int i = 0; i < 127; i++) {
		CONSOLE::gotoXY(i + coord.X, 6 + coord.Y);
		cout << char(254);
		Sleep(7);
	}

	CONSOLE::textcolor(15);
	fi.close();
}


/**************************************************************
* Hàm vẽ màn hình game over
* Các tham số:
* coord		: Tọa độ.
* color		: Màu sắc.
* isSound	: Âm thanh.
***************************************************************/
void CDRAW::drawGameOverScreen(COORD coord, SHORT color, bool isSound) {
	ifstream fi("Text/GameOver.txt");
	if (fi.fail()) return;

	if (isSound) {
		mciSendString(TEXT("close mp3"), NULL, 0, NULL);
		mciSendString(TEXT("open \"OST/mixkit-game-over-dark-orchestra.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
		mciSendString(TEXT("play mp3"), NULL, 0, NULL);
	}

	// Đổi lại màu màn hình thành màu đen
	system("color 0e");

	// Vẽ khung
	CDRAW::drawBox(COORD{ 1,1 }, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2,
		219, 219, 219, 219, 219, 219, 11);

	// Đổi màu kí tự:
	CONSOLE::textcolor(color);
	string s;

	// Vẽ chữ game over:
	for (int i = 0; !fi.eof(); i++) {
		getline(fi, s);
		replace(s.begin(), s.end(), '#', char(254)); // Thay tất cả ký tự '#' trong chuỗi bằng ký tự '■'
		CONSOLE::gotoXY(coord.X, coord.Y + i);
		cout << s;
		Sleep(50);
	}

	CONSOLE::textcolor(15);
	Sleep(500);
	fi.close();

	//******************************

	// Viết dòng chữ "Don't give up! :))":
	fi.open("Text/Ease.txt");
	if (fi.fail()) return;

	char c;
	CONSOLE::gotoXY(coord.X + 30, coord.Y + 10);

	if (isSound) PlaySound(TEXT("OST/Typing.wav"), NULL, SND_ASYNC);
	for (int i = 0; i < 18; i++) {
		fi.get(c);
		cout << c;
		Sleep(75);
	}

	fi.close();
}

/**************************************************************
* Hàm vẽ màn hình level complete
* Các tham số tương tự hàm vẽ màn hình game over
***************************************************************/
void CDRAW::drawLevelCompleteScreen(COORD coord, SHORT color, bool isSound)
{
	ifstream fi("Text/LevelComplete.txt");
	if (fi.fail()) return;

	if (isSound) {
		mciSendString(TEXT("close mp3"), NULL, 0, NULL);
		mciSendString(TEXT("open \"OST/mixkit-game-level-completed.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
		mciSendString(TEXT("play mp3"), NULL, 0, NULL);
	}

	// Đổi lại màu màn hình thành màu đen
	system("color 0e");

	// Vẽ khung
	CDRAW::drawBox(COORD{ 1,1 }, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2,
		219, 219, 219, 219, 219, 219, 11);

	// Đổi màu kí tự:
	CONSOLE::textcolor(color);
	string s;

	for (int i = 0; !fi.eof(); i++) {
		getline(fi, s);
		replace(s.begin(), s.end(), '#', char(254));
		CONSOLE::gotoXY(coord.X, coord.Y + i);
		cout << s;
		Sleep(50);
	}

	CONSOLE::textcolor(15);
	fi.close();
}