#include"CGAME.h"

CGAME::CGAME() {
	is_Running = true;
	srand(time(NULL));
}

void CGAME::drawGame() {
	system("color 7a");

	short colorText = ColorGame::navi;
	short heightRoad = SCREEN_GAME_HEIGHT / NUMBER_ROAD;

	CDRAW::drawBox(COORD{ SCREEN_GAME_RECT_X, SCREEN_GAME_RECT_Y }, SCREEN_GAME_WIDTH, SCREEN_GAME_HEIGHT,
		223, 219, 219, 219, 223, 223, colorText);

	short width = SCREEN_GAME_WIDTH - 1;
	short x = SCREEN_GAME_RECT_X + 1;
	short y = SCREEN_GAME_RECT_Y;
	short typeChar = 61;

	for (short i = 1; i < NUMBER_ROAD; i++) {
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

void CGAME::resetGame(short level) {
	if (level < 1)
		level = 1;

	// xóa dữ liệu objects cũ
	clearGame();
	people.setPosition((GameScreen::sLEFT + GameScreen::sRIGHT) / 2, GameScreen::sBOTTOM - people.getHeightPeople());

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

	short heightLane = SCREEN_GAME_HEIGHT / NUMBER_ROAD;
	short deltaSpeed = 10 * (level - 1);
	short before_x, distance;

	carLeft = new CCAR[numCar];
	truckLeft = new CTRUCK[numTruck];
	carRight = new CCAR[numCar];
	truckRight = new CTRUCK[numTruck];

	// set Car
	for (short i = 0; i < numCar; i++) {
		if (i == 0) { // set Car đầu tiên trong mảng
			// làn đường số 3
			carLeft[i].set(sRIGHT + 1, 1 + 3 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, 1, LEFT);
			carLeft[i].setSpeed((level % 7 / 3 + 3));

			// làn đường số 4
			carRight[i].set(sLEFT - carRight[i].getWidth(), 1 + 4 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, 2, RIGHT);
			carRight[i].setSpeed((level % 7 / 3 + 2));
		}
		else {		  // set các Car còn lại dựa theo tọa độ Car đầu tiên
			// lấy tọa độ x của xe phía trước
			before_x = carLeft[i - 1].getX();
			// lấy khoảng các ngẫu nhiên so với xe trước
			distance = randomDistance(before_x, numCar - i - 1, carLeft[i].getWidth(), sRIGHT + SCREEN_GAME_WIDTH);

			// set cho các xe còn lại
			carLeft[i].set(before_x + distance + carLeft[i].getWidth(), 1 + 3 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, 1, LEFT);
			carLeft[i].setSpeed((level % 7 / 3 + 3));

			carRight[i].set(carRight[i - 1].getX() - carRight[i].getWidth() - distance, 1 + 4 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, 2, RIGHT);
			carRight[i].setSpeed((level % 7 / 3 + 2));
		}
	}

	// set Truck
	for (short i = 0; i < numTruck; i++) {
		if (i == 0) {
			// làn đường số 5
			truckLeft[i].set(sRIGHT + 1, 1 + 5 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 110 - deltaSpeed, 1, LEFT);
			truckLeft[i].setSpeed((level + 2) % 3 + 3);

			// làn đường số 6
			truckRight[i].set(sLEFT - truckRight[i].getWidth(), 1 + 6 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 110 - deltaSpeed, 2, RIGHT);
			truckRight[i].setSpeed(((level + 3) / 3 % 4 + 2));
		}
		else {
			before_x = truckLeft[i - 1].getX();
			distance = randomDistance(before_x, numTruck - i - 1, truckLeft[i].getWidth(), sRIGHT + SCREEN_GAME_WIDTH);

			truckLeft[i].set(before_x + truckLeft[i].getWidth() + distance, 1 + 5 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 110 - deltaSpeed, 1, LEFT);
			truckLeft[i].setSpeed((level + 2) % 3 + 3);

			truckRight[i].set(truckRight[i - 1].getX() - truckRight[i].getWidth() - distance, 1 + 6 * heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 110 - deltaSpeed, 2, RIGHT);
			truckRight[i].setSpeed(((level + 3) / 3 % 4 + 2));
		}
	}

	// set Horse
	horse = new CHORSE[numHorse];
	short move = level % 2 == 0 ? LEFT : RIGHT;	// chạy qua trái hoặc phải
	short x_cur;

	for (short i = 0; i < numHorse; i++) {
		if (i == 0) {
			// xác định tọa độ x theo chiều xe chạy
			if (move == LEFT)
				x_cur = sRIGHT + 1;
			else 
				x_cur = sLEFT - horse[0].getWidth();
			
			// làn đường số 1
			horse[i].set(x_cur, 1 + heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, move);
			horse[i].setSpeed(((level * 2 + 1) / 3) % 3 + 3);
		}
		else {
			before_x = horse[i - 1].getX();
			distance = randomDistance(before_x, numHorse - i - 1, horse[i].getWidth() , sRIGHT + SCREEN_GAME_WIDTH);

			if (move == LEFT)
				x_cur = before_x + horse[i].getWidth() + distance;
			else
				x_cur = before_x - horse[i].getWidth() - distance;

			horse[i].set(x_cur, 1 + heightLane,
				randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, move);
			horse[i].setSpeed(((level * 2 + 1) / 3) % 3 + 3);
		}
	}

	// set rabbit
	move = level % 5 != 0 ? LEFT : RIGHT;	// chạy qua trái hoặc phải

	if (level <= 4) {
		rabbit = new CRABBIT[numRabbit];
		for (short i = 0; i < numRabbit; i++) {
			if (i == 0) {
				if (move == LEFT)
					x_cur = sRIGHT + 1;
				else
					x_cur = sLEFT - rabbit[0].getWidth();

				// làn đường số 2
				rabbit[i].set(x_cur, 1 + 2 * heightLane,
					randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, move);
				rabbit[i].setSpeed(level);
			}
			else {
				before_x = rabbit[i - 1].getX();
				distance = randomDistance(before_x, numRabbit - i - 1, rabbit[i].getWidth(), sRIGHT + SCREEN_GAME_WIDTH);

				if (move == LEFT)
					x_cur = before_x + rabbit[i].getWidth() + distance;
				else
					x_cur = before_x - rabbit[i].getWidth() - distance;

				rabbit[i].set(x_cur, 1 + 2 * heightLane,
					randomColor(ColorGame::black, ColorGame::olive), 120 - deltaSpeed, move);
				rabbit[i].setSpeed(level);
			}
		}
	}
	else {
		numRabbit = 0;
		rabbit = new CRABBIT[numRabbit];
		// train

	}
}

CPEOPLE CGAME::getPeople()
{
	return people;
}

void CGAME::clearGame() {
	delete[] carLeft;
	delete[] carRight;
	delete[] truckLeft;
	delete[] truckRight;
	delete[] horse;
	delete[] rabbit;
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

void CGAME::updatePosVehicle() {
	for (short i = 0; i < numCar; i++) {
		carLeft[i].move();
		carRight[i].move();
	}
	for (short i = 0; i < numTruck; i++) {
		truckLeft[i].move();
		truckRight[i].move();
	}
}

void CGAME::updatePosAnimal() {
	for (short i = 0; i < numHorse; i++)
		horse[i].move();
	for (short i = 0; i < numRabbit; i++)
		rabbit[i].move();
}

void CGAME::drawObjects(short key) {
	for (short i = 0; i < numCar; i++) {
		carLeft[i].draw();
		carRight[i].draw();
	}
	for (short i = 0; i < numTruck; i++) {
		truckLeft[i].draw();
		truckRight[i].draw();
	}

	for (short i = 0; i < numHorse; i++)
		horse[i].draw();
	for (short i = 0; i < numRabbit; i++)
		rabbit[i].draw();

	//people.draw(key);
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