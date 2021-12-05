#include"CGAME.h"

CGAME::CGAME() {
	is_Running = true;
	currentLevel = 1;
	score = 0;
	srand(time(NULL));
	username = "";

	// Đọc các cài đặt âm thanh từ file
	/*ifstream fi("Text/OST.txt");
	if (fi.fail()) return;

	char c;
	fi >> c;
	if (c == '1') isSound = true;
	else isSound = false;

	fi >> c;
	if (c == '1') isMusic = true;
	else isMusic = false;

	fi.close();*/
	isMusic = true;
	isSound = true;
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
		else if (i == 2)
			CDRAW::drawHorizontalLine(COORD{ x, tempY }, width, 61, colorText);
	}

	// Vẽ hướng dẫn
	drawGuide();
	// Vẽ thông tin người chơi
	drawInforLevel();
}

// Lấy màu ngẫu nhiên
short CGAME::randomColor(short start, short end) {
	while (1) {
		int ran = rand() % (end - start + 1) + start;
		if (ran >= start && ran <= end)
			return ran;
	}
}

// Set lại các đối tượng của level
void CGAME::resetGame(short level) {
	if (level < 1)
		level = currentLevel;

	// xóa dữ liệu objects cũ
	clearGame();
	// set lại vị trí người về điểm xuất phát
	people.setPosition(GameScreen::sLEFT + 4, GameScreen::sBOTTOM - people.getHeightPeople());
	people.setSound(isSound);

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
	lane3->setLane(numCar, (level % 7 / 3 + 3), LEFT, carFormLeft1, carFormLeft2);
	lane4->setLane(numCar, (level % 7 / 3 + 2), RIGHT, carFormRight2, carFormRight2);

	// set Truck
	lane5->setLane(numTruck, (level + 2) % 3 + 3, LEFT, truckFormLeft1, truckFormLeft2);
	lane6->setLane(numTruck, (level + 3) / 3 % 4 + 2, RIGHT, truckFormRight2, truckFormRight2);

	// set Horse
	short move = (level % 2) == 0 ? LEFT : RIGHT;	// chạy qua trái hoặc phải phụ thuộc vào level
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
		if (move == LEFT)
			laneTrain->setLane(1, 7 % 4 + 2, move, trainFormLeft, { {} });
		else 
			laneTrain->setLane(1, 7 % 4 + 2, move, trainFormRight, { {} });
	}
}

void CGAME::saveGame(fstream& save)
{
	save << currentLevel << " " << score << endl;
	save << people.getX() << " " << people.getY() << endl;

	//Save objects of lane
	vector<CANIMAL*> animals;
	vector<CVEHICLE*> vehicles;
	int size, sizeLane = 7;
	if (currentLevel <= 4) sizeLane--;

	for (int i = 1; i <= sizeLane; i++) {
		switch (i)
		{
		case 1:
			animals = lane1->getListObjs();
			size = numHorse;
			break;
		case 2:
			animals = lane2->getListObjs();
			size = numRabbit;
			break;
		case 3:
			vehicles = lane3->getListObjs();
			size = numCar;
			break;
		case 4:
			vehicles = lane4->getListObjs();
			size = numCar;
			break;
		case 5:
			vehicles = lane5->getListObjs();
			size = numTruck;
			break;
		case 6:
			vehicles = lane6->getListObjs();
			size = numTruck;
			break;
		case 7:
			size = 1;
			vehicles = laneTrain->getListObjs();
			break;
		}

		save << size << endl;

		if (i < 3) {

			for (int j = 0; j < size; j++) {
				save << animals[j]->getX() << " " << animals[j]->getY() << " "
					<< animals[j]->getColor() << " " << animals[j]->getMove() << " "
					<< animals[j]->getSpeed() << endl;
			}
			animals.clear();
		}
		else {
			for (int j = 0; j < size; j++) {
				save << vehicles[j]->getX() << " " << vehicles[j]->getY() << " "
					<< vehicles[j]->getColor() << " " << vehicles[j]->getMove() << " "
					<< vehicles[j]->getSpeed() << endl;
			}
			vehicles.clear();
		}
	}

	save.close();
}

void CGAME::loadGame(fstream& load)
{
	short xPeople, yPeople, size;
	short xObj, yObj, colorO, moveO, speedO;

	load >> currentLevel >> score;
	//load.get();

	load >> xPeople >> yPeople;
	people.setPosition(xPeople, yPeople);
	load.get();

	for (int i = 1; i <= 6; i++) {
		load >> size;
		load.get();

		for (int j = 0; j < size; j++)
		{
			load >> xObj >> yObj >> colorO >> moveO >> speedO;
			load.get();
			switch (i)
			{
			case 1:
				numHorse = size;
				if (moveO == LEFT)	
					lane1->pushObj(xObj, yObj, colorO, moveO, speedO, horseLeft_1, horseLeft_2);
				else				
					lane1->pushObj(xObj, yObj, colorO, moveO, speedO, horseRight_1, horseRight_2);
				break;
			case 2:
				numRabbit = size;
				if (moveO == LEFT)	
					lane2->pushObj(xObj, yObj, colorO, moveO, speedO, rabbitLeft_1, rabbitLeft_2);
				else				
					lane2->pushObj(xObj, yObj, colorO, moveO, speedO, rabbitRight_1, rabbitRight_2);
				break;
			case 3:
				numCar = size;
				lane3->pushObj(xObj, yObj, colorO, moveO, speedO, carFormLeft1, carFormLeft2);
				break;
			case 4:		
				numCar = size;
				lane4->pushObj(xObj, yObj, colorO, moveO, speedO, carFormRight2, carFormRight2);
				break;
			case 5:
				numTruck = size;
				lane5->pushObj(xObj, yObj, colorO, moveO, speedO, truckFormLeft1, truckFormLeft2);
				break;
			case 6:	
				numTruck = size;
				lane6->pushObj(xObj, yObj, colorO, moveO, speedO, truckFormRight2, truckFormRight2);
				break;
			case 7:
				if (currentLevel > 4 && numRabbit == 0) {
					if (moveO == LEFT)
						laneTrain->pushObj(xObj, yObj, colorO, moveO, speedO, trainFormLeft, { {} });
					else
						laneTrain->pushObj(xObj, yObj, colorO, moveO, speedO, trainFormRight, { {} });
				}
				break;
			}
		}
	}

	load.close();
}

// Remove các đối tượng
void CGAME::clearGame() {
	lane1->clearObjs();
	lane2->clearObjs();
	lane3->clearObjs();
	lane4->clearObjs();
	lane5->clearObjs();
	lane6->clearObjs();
	laneTrain->clearObjs();
}

// Vẽ Title, Menu.... khi mở game
bool CGAME::runApp(bool check) {
	system("color 0e");
	short charType = 219;

	// Vẽ khung màn hình
	CDRAW::drawBox(COORD{ 1,1 }, SCREEN_CONSOLE_WIDTH - 1, SCREEN_CONSOLE_HEIGHT - 2,
		charType, charType, charType, charType, charType, charType, 11);

	if (check == true) {
		// Vẽ trailer
		CDRAW::drawLogo(COORD{ 36, 5 }, 10, 500, isSound);
	}
	CDRAW::drawTitle(COORD{ 10, 4 }, 151, isSound);

	int choice;

	// MENU
	while (1) {
		// Menu chính
		CMENU cmenu = CMENU(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 1 }, 30, isSound);
		cmenu.addItem("Play game");
		cmenu.addItem("Load game");
		cmenu.addItem("High score");
		cmenu.addItem("Settings");
		cmenu.addItem("Quit");
		choice = cmenu.getSelectFromUser();
		CDRAW::clearBox(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2, SCREEN_CONSOLE_HEIGHT / 2 + 1 }, 1, 32, 5 * 2 + 1);
		
		bool checkFile = true; string str;

		choice++;
		switch (choice) 
		{
		case 1: {
			CMENU inputUser = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 20 }, 24, isSound);
			inputUser.addItem("WELCOME");
			inputUser.addItem("Enter your username");
			inputUser.setColorTitle(46);
			username = inputUser.getInputString();

			mciSendString(TEXT("close mp3"), NULL, 0, NULL);
			return true;
		}
		case 2:
			Load_game(checkFile, str);

			while (!checkFile)
			{
				CMENU loadForm = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, getSound());
				loadForm.addItem("Wrong filename!!!");
				loadForm.addItem("\"Cancel\": to resume");
				loadForm.displayTableLine();
				Load_game(checkFile, str);
				if (str == "Cancel") break;
			}
			mciSendString(TEXT("close mp3"), NULL, 0, NULL);
			return true;
		case 3:
			// high score

			break;
		case 4: {
			// Menu setting
			Settings();
			break;
		}
		case 5:
			// exit
			system("cls");
			return false;
		}
	}

	// Lưu các cài đặt âm thanh ra file
	/*ofstream fo("Text/OST.txt");
	fo << isSound << endl << isMusic;
	fo.close();*/
}

// Vẽ hướng dẫn trò chơi
void CGAME::drawGuide() {
	CMENU guide = CMENU(COORD{ SCREEN_GAME_WIDTH + 11, SCREEN_CONSOLE_HEIGHT / 2 + 1 }, 24);
	guide.addItem("GUIDE");
	guide.addItem("");
	guide.addItem("W: up  ");
	guide.addItem("S: Down");
	guide.addItem("A: Left");
	guide.addItem("D: Right");
	guide.addItem("");
	guide.addItem("L  : Save game ");
	guide.addItem("T  : Load game ");
	guide.addItem("P  : Pause game");
	guide.addItem("U  : Settings  ");
	guide.addItem("ESC: Exit game ");

	guide.setColorTable(ColorGame::black, ColorGame::blue);
	guide.displayTableNoneLine();
}

void CGAME::drawInforLevel()
{
	CMENU information = CMENU(COORD{ SCREEN_GAME_WIDTH + 11, SCREEN_CONSOLE_HEIGHT / 4 - 2}, 24);
	information.addItem(username);
	information.addItem("");
	information.addItem("Level: " + to_string(currentLevel));
	information.addItem("Score: " + to_string(score));
	information.addItem("");

	information.setColorTable(ColorGame::black, ColorGame::green);
	information.setColorTitle(ColorGame::pink);
	information.displayTableNoneLine();
}

void CGAME::setLevel(short lev)
{
	if (lev > 0)
		currentLevel = lev;
}

// Update vị trí của Vehicle
void CGAME::updatePosVehicle() {
	if (lane3->getNumObjs() > 0) {
		lane3->setTimerLight(500, 50);
		lane3->moveObj();
		if (isSound)
			lane3->tellObj();
	}
	if (lane4->getNumObjs() > 0) {
		lane4->setTimerLight(400, 50);
		lane4->moveObj();
		if (isSound)
			lane4->tellObj();
	}
	if (lane5->getNumObjs() > 0) {
		lane5->setTimerLight(450, 60);
		lane5->moveObj();
		if (isSound)
			lane5->tellObj();
	}
	if (lane6->getNumObjs() > 0) {
		lane6->setTimerLight(300, 70);
		lane6->moveObj();
		if (isSound)
			lane6->tellObj();
	}
	if (currentLevel > 4) {
		laneTrain->setTimerLight((6 - (7 % 4 + 2)) * (SCREEN_GAME_WIDTH + 1) + 64, 100);
		laneTrain->moveObj();
		if (isSound)
			laneTrain->tellObj();
	}
}

// Update vị trí của Animal
void CGAME::updatePosAnimal() {
	lane1->moveObj();
	if (isSound)
		lane1->tellObj();
	if (currentLevel <= 4) {
		lane2->moveObj();
		if (isSound)
			lane2->tellObj();
	}
}

// Vẽ các đối tượng
void CGAME::drawObjects(short key) {
	lane1->drawObj();
	lane2->drawObj();
	lane3->drawObj();
	lane4->drawObj();
	lane5->drawObj();
	lane6->drawObj();
	laneTrain->drawObj();
}

// Update vị trí con người
void CGAME::updatePosPeople(short key) {
	switch (key) {
	case Key::UP:
		if (people.up()) {
			people.draw(key);
		}
		break;
	case Key::DOWN:
		if (people.down()) {
			people.draw(key);
		}
		break;
	case Key::LEFT:
		if (people.left()) {
			people.draw(key);
		}
		break;
	case Key::RIGHT:
		if (people.right()) {
			people.draw(key);
		}
		break;
	default:
		people.draw(key);
		break;
	}
}

// Tạm dừng game
void CGAME::pauseGame(thread* t) {
	is_Running = false;
	if (t != nullptr) {
		t->join();
		t = nullptr;
	}
}

// Tiếp tục game
void CGAME::resumeGame(void (*f)(), thread* t) {
	is_Running = true;
	if (t != nullptr)
		*t = thread(f);
}

// Phát nhạc
void CGAME::startMusic()
{
	mciSendString(TEXT("close mp3"), NULL, 0, NULL);

	mciSendString(TEXT("open \"OST/ForestWalk.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	if (isMusic) {
		mciSendString(TEXT("play mp3"), NULL, 0, NULL);
	}
}

// Play/Pause music
void CGAME::MusicStatus(bool play)
{
	if (isMusic) {
		if (play)
			mciSendString(TEXT("play mp3"), NULL, 0, NULL);
		else
			mciSendString(TEXT("pause mp3"), NULL, 0, NULL);
	}
}

// Process Win and next Level
bool CGAME::Win_nextLevel()
{
	system("cls");

	// Vẽ màn hình Win
	CDRAW::drawLevelCompleteScreen(COORD{ 12, 5 }, 10, isSound);
	currentLevel++;
	score += currentLevel * 50;

	// menu
	CMENU menu = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 23 }, 24, isSound);
	menu.addItem("Next Level");
	menu.addItem("Save game");
	menu.addItem("Quit");
	menu.displayTableLine();
	short choice = menu.getSelectFromUser();
	CDRAW::clearBox(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 23 }, 236, 26, 2 * 3 + 1);

	if (choice == 0) {
		resetGame();
	}
	else if (choice == 1) {
		Save_game();
	}
	else if (choice == 2) {
		// exit
		return true;
	}
	return false;
}

// Process Game over
bool CGAME::Game_over()
{
	system("cls");

	// Vẽ 
	CDRAW::drawGameOverScreen(COORD{ 33, 5 }, 4, isSound);

	// menu
	CMENU menu = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 23 }, 24, isSound);
	menu.addItem("Play again");
	menu.addItem("Load game");
	menu.addItem("Quit");
	menu.displayTableLine();
	short choice = menu.getSelectFromUser();
	CDRAW::clearBox(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 23 }, 236, 26, 2 * 3 + 1);

	if (choice == 0) {
		setLevel(1);
		score = 0;
		resetGame();
	}
	else if (choice == 1) {
		bool checkFile = true; string str;
		Load_game(checkFile, str);
		while (!checkFile)
		{
			CMENU loadForm = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, getSound());
			loadForm.addItem("Wrong filename!!!");
			loadForm.addItem("\"Cancel\": to resume");
			loadForm.displayTableLine();
			Load_game(checkFile, str);
			if (str == "Cancel") break;
		}
	}
	else if (choice == 2) {
		// exit
		return true;
	}
	return false;
}

// Process ESC
bool CGAME::ESC()
{
	// menu
	CMENU menu = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, isSound);
	menu.addItem("Resume");
	menu.addItem("Save game");
	menu.addItem("Quit");
	menu.displayTableLine();
	short choice = menu.getSelectFromUser();
	CDRAW::clearBox(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 236, 26, 2 * 3 + 1);

	if (choice == 0) {
		return false;
	}
	else if (choice == 1) {
		Save_game();
		return false;
	}
	return true;
}

void CGAME::Settings()
{
	CMENU settingMenu = CMENU(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2 + 2, SCREEN_CONSOLE_HEIGHT / 2 + 2 }, 26, isSound);
	settingMenu.addItem("Sound");
	settingMenu.addItem("Music");
	settingMenu.addItem("Apply");
	settingMenu.getSettingFromUser(isSound, isMusic);
	CDRAW::clearBox(COORD{ (SCREEN_CONSOLE_WIDTH - 30) / 2 + 2, SCREEN_CONSOLE_HEIGHT / 2 + 2 }, 1, 28, 3 * 2 + 1);
	if (!isMusic)
		mciSendString(TEXT("pause mp3"), NULL, 0, NULL);
	else mciSendString(TEXT("play mp3"), NULL, 0, NULL);
	people.setSound(isSound);
}

// Process Save game
void CGAME::Save_game()
{
	CMENU saveForm = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 16 }, 24, this->getSound());
	saveForm.addItem("SAVE GAME");
	saveForm.addItem("Enter file \"name\".txt");
	saveForm.setColorTitle(46);
	string filename = saveForm.getInputString();

	// xử lý save game
	if (filename.find(".txt", 0) != 0) filename += ".txt";
	fstream saveG;
	saveG.open(filename, ios::out);
	saveGame(saveG);
}

// Process Load game
void CGAME::Load_game(bool& check, string& str)
{
	CMENU inputFileName = CMENU(COORD{ SCREEN_CONSOLE_WIDTH / 2 - 14, sTOP + 20 }, 24, isSound);
	inputFileName.addItem("LOAD GAME");
	inputFileName.addItem("Enter file \"name\".txt");
	inputFileName.setColorTitle(46);
	string filename = inputFileName.getInputString();
	str = filename;

	// xử lý load game
	if (filename.find(".txt", 0) != 0) filename += ".txt";

	fstream loadG;
	loadG.open(filename, ios::in);

	if (!loadG) {
		check = false;
		return;
	}
	else check = true;
	//Clear objects on the lane
	clearGame();
             
	loadGame(loadG);
}

// Exit game
void CGAME::Exit_game(thread* run)
{
	is_Running = false;
	if (run != nullptr)
		run->join();
	system("cls");
	system("color 0e");
}
