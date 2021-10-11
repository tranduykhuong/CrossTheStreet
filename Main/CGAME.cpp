#include"CGAME.h"

void CGAME::drawGame() {
	int colorText = 15;
	cdraw.drawBox(SCREEN_GAME_RECT_X, SCREEN_GAME_RECT_Y, SCREEN_GAME_WIDTH, SCREEN_GAME_HEIGHT, 
		205, 186, 201, 187, 200, 188, colorText);

	int width = SCREEN_GAME_WIDTH - 1;
	int x = SCREEN_GAME_RECT_X + 1;
	int y = SCREEN_GAME_RECT_Y;
	int typeChar = 45;

	for (int i = 1; i < NUMBER_ROAD; i++) {
		cdraw.drawHorizontalLine(x, y + 5*i, width, typeChar, 15);
	}
}

void CGAME::drawMenuGame() {
	cdraw.drawBox(1, 1, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2, 178, 178, 178, 178, 178, 178, 15);
	int x_name = 9;
	int y_name = SCREEN_CONSOLE_HEIGHT / 3;

	for (int i = 1; i < 4; i++) {
		int color = i % 15;
		cdraw.drawGameName("nameGametr.txt", x_name, y_name, color, 200);
	}
	for (int i = 4; i <= 10; i += 2) {
		--y_name;
		cdraw.drawGameName("nameGametr.txt", x_name, y_name, i, 50);
	}
	int choice;

	cmenu.addOption("Play game");
	cmenu.addOption("Load game");
	cmenu.addOption("Help");
	cmenu.addOption("Quit");
	cmenu.displayTable();
	choice = cmenu.getSelectFromUser();
}