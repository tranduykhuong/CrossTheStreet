#include"CGAME.h"

CGAME::CGAME() {
	is_Running = true;
	srand(time(NULL));

	// Đọc các cài đặt âm thanh từ file
	ifstream fi("Text/OST.txt");
	if (fi.fail()) return;

	char c;
	fi >> c;
	if (c == '1') isSound = true;
	else isSound = false;

	fi >> c;
	if (c == '1') isMusic = true;
	else isMusic = false;

	fi.close();
}

// Vẽ màn hình Game
void CGAME::drawGame() {
	system("color E2");

	short colorText = ColorGame::black;

	// Vẽ khung game
	CDRAW::drawBox(COORD{ SCREEN_GAME_RECT_X, SCREEN_GAME_RECT_Y }, SCREEN_GAME_WIDTH, SCREEN_GAME_HEIGHT,
		223, 219, 219, 219, 223, 223, colorText);

	short width = SCREEN_GAME_WIDTH - 1;
	short x = SCREEN_GAME_RECT_X + 1;
	short y = SCREEN_GAME_RECT_Y;
	short typeChar = 61;

	// Vẽ các Lane
	short numRoad = SCREEN_GAME_HEIGHT / HEIGHT_ROAD;
	for (short i = 1; i < numRoad; i++) {
		short tempY = y + HEIGHT_ROAD * i;
		if (i % 2 != 0)
			CDRAW::drawHorizontalLine(COORD{ x, tempY }, width, 22, colorText);
		else if (i == numRoad - 2 || i == numRoad - 4) {
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

short CGAME::randomDistance(short x_before, short num, short widthObs, short screenRight) {
	short delta = num * (widthObs + 3);
	while(1) {
		int ran = rand() % 40 + 3;
		if (x_before + ran + 2 * widthObs + delta + 2 < screenRight)
			return ran;
	}
}
short CGAME::randomDistance_RIGHT(short x_before, short num, short widthObs, short screenLeft) {
	short delta = num * (widthObs + 3);
	while (1) {
		int ran = rand() % 40 + 3;
		if (x_before - ran - widthObs - delta - 2 > screenLeft)
			return ran;
	}
}

short CGAME::randomColor(short start, short end) {
	while (1) {
		int ran = rand() % (end - start + 1) + start;
		if (ran >= start && ran <= end)
			return ran;
	}
}

// Set lại các đối tượng
void CGAME::resetGame(short level) {
	if (level < 1)
		level = 1;

	// xóa dữ liệu objects cũ
	clearGame();
	// set lại vị trí người về điểm xuất phát
	people.setPosition(GameScreen::sLEFT + 4, GameScreen::sBOTTOM - people.getHeightPeople());

	// xác định số lượng object ở mỗi level
	numCar = ((level + 1) / 2 + 1) % 4 + 2;
	numTruck = ((numCar + 2) / 2) % 6;
	numHorse = (level - 1) / 3 * 3 % 7;
	numRabbit = numHorse / 2 + 3;
	if (level == 1) {
		numTruck = 0;
		numRabbit = 0;
	}
	else if (level == 2) {
		numRabbit = 0;
	}

	// set Car
	lane3->setLane(numCar, (level % 7 / 3 + 3), LEFT, carFormLeft1, { {} });
	lane4->setLane(numCar, (level % 7 / 3 + 2), RIGHT, carFormRight2, { {} });

	// set Truck
	lane5->setLane(numTruck, (level + 2) % 3 + 3, LEFT, truckFormLeft1, { {} });
	lane6->setLane(numTruck, (level + 3) / 3 % 4 + 2, RIGHT, truckFormRight2, { {} });

	// set Horse
	short move = level % 2 == 0 ? LEFT : RIGHT;	// chạy qua trái hoặc phải phụ thuộc vào level
	if (move == LEFT)
		lane1->setLane(numHorse, ((level * 2 + 1) / 3) % 3 + 3, move, horseLeft_1, horseLeft_2);
	else
		lane1->setLane(numHorse, ((level * 2 + 1) / 3) % 3 + 3, move, horseRight_1, horseRight_2);

	// set rabbit
	move = level % 5 != 0 ? LEFT : RIGHT;		// chạy qua trái hoặc phải

	if (level <= 4) {
		if (move == LEFT)
			lane2->setLane(numRabbit, level, move, rabbitLeft_1, rabbitLeft_2);
		else
			lane2->setLane(numRabbit, level, move, rabbitRight_1, rabbitRight_2);
	}
	else {
		numRabbit = 0;

		// train

	}
}

// Remove các đối tượng
void CGAME::clearGame() {
	lane1->clearObjs();
	lane2->clearObjs();
	lane3->clearObjs();
	lane4->clearObjs();
	lane5->clearObjs();
	lane6->clearObjs();
}

// Vẽ Title, Menu....
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

	// Menu chính
	/*CMENU cmenu = CMENU(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 2 }, 30);
	cmenu.addItem("Play game");
	cmenu.addItem("Load game");
	cmenu.addItem("Help");
	cmenu.addItem("Quit");
	choice = cmenu.getSelectFromUser();*/

	// Menu setting Music and Sound
	CMENU cmenu = CMENU(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 2 }, 26, isSound);
	cmenu.addItem("Sound");
	cmenu.addItem("Music");
	cmenu.addItem("Apply");
	//bool a = , b = 1;
	cmenu.getSettingFromUser(isSound, isMusic);


	// Music
	if (isMusic) {
		mciSendString(TEXT("open \"OST/ForestWalk.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
		mciSendString(TEXT("play mp3 repeat"), NULL, 0, NULL);
	}
	else mciSendString(TEXT("close mp3"), NULL, 0, NULL);

	// Lưu các cài đặt âm thanh ra file
	ofstream fo("Text/OST.txt");
	fo << isSound << endl << isMusic;
	fo.close();
}

// Vẽ hướng dẫn trò chơi
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

void CGAME::updatePosVehicle() {
	lane3->moveObj();
	lane4->moveObj();
	lane5->moveObj();
	lane6->moveObj();
}

void CGAME::updatePosAnimal() {
	lane1->moveObj();
	lane2->moveObj();
}

void CGAME::drawObjects(short key) {
	lane1->drawObj();
	lane2->drawObj();
	lane3->drawObj();
	lane4->drawObj();
	lane5->drawObj();
	lane6->drawObj();
}

void CGAME::updatePosPeople(short key) {
	switch (key) {
	case Key::UP:
		people.up();
		break;
	case Key::DOWN:
		people.down();
		break;
	case Key::LEFT:
		people.left();
		break;
	case Key::RIGHT:
		people.right();
		break;
	default:
		break;
	}
	people.draw(key);
}