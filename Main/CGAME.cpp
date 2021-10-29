#include"CGAME.h"

CGAME::CGAME() {

}

void CGAME::drawGame() {
	short colorText = ColorGame::navi;
	short heightRoad = SCREEN_GAME_HEIGHT / NUMBER_ROAD;

	CDRAW::drawBox(COORD{ SCREEN_GAME_RECT_X, SCREEN_GAME_RECT_Y }, SCREEN_GAME_WIDTH, SCREEN_GAME_HEIGHT,
		223, 219, 219, 219, 223, 223, colorText);

	short width = SCREEN_GAME_WIDTH - 1;
	short x = SCREEN_GAME_RECT_X + 1;
	short y = SCREEN_GAME_RECT_Y;
	short typeChar = 61;

	for (int i = 1; i < NUMBER_ROAD; i++) {
		short tempY = y + heightRoad * i;
		if (i % 2 != 0)
			CDRAW::drawHorizontalLine(COORD{ x, tempY }, width, 22, colorText);
		else if (i == NUMBER_ROAD - 2 || i == NUMBER_ROAD - 4) {
			CDRAW::drawHorizontalLine(COORD{ x, tempY }, width, 205, colorText);
			for (int j = x; j < x + width; j += 2) {
				CONSOLE::gotoXY(j, tempY);
				cout << char(32);
			}
		}
		else if (i==2)
			CDRAW::drawHorizontalLine(COORD{ x, tempY }, width, 61, colorText);

	}
	
}

void CGAME::runApp() {
	system("color 0e");
	short charType = 219;

	CDRAW::drawBox(COORD{ 1,1 }, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2,
		charType, charType, charType, charType, charType, charType, 11);

	short x_name = 9;
	short y_name = SCREEN_CONSOLE_HEIGHT / 3;

	/*for (int i = 1; i < 4; i++) {
		int color = i % 15;
		CDRAW::drawGameTXT("nameGametr.txt", COORD{ x_name, y_name }, color, 200);
	}
	for (int i = 4; i <= 10; i += 2) {
		--y_name;
		CDRAW::drawGameTXT("nameGametr.txt", COORD{ x_name, y_name }, i, 50);
	}*/
	int choice;

	CMENU cmenu = CMENU(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 2 }, 30);
	cmenu.addItem("Play game");
	cmenu.addItem("Load game");
	cmenu.addItem("Help");
	cmenu.addItem("Quit");
	choice = cmenu.getSelectFromUser();

	/*CMENU cmenu = CMENU(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 2 }, 26);
	cmenu.addItem("Sound");
	cmenu.addItem("Music");
	cmenu.addItem("Apply");
	bool a = false, b;
	cmenu.getSettingFromUser(a, b);*/
}

void CGAME::drawGuide() {
	CMENU guide = CMENU(COORD{ SCREEN_GAME_WIDTH + 7, SCREEN_CONSOLE_HEIGHT / 2 + 5 }, 24);
	guide.addItem("GUIDE");
	guide.addItem("");
	guide.addItem("W: up");
	guide.addItem("S: Down");
	guide.addItem("A: Left");
	guide.addItem("D: Right");
	guide.setColorTable(ColorGame::black, ColorGame::blue);
	guide.displayTableNoneLine();
}