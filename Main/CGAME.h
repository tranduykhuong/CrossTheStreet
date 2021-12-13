#pragma once
#include"CONSOLE.h"
#include"CDRAW.h"
#include"CMENU.h"

#include"CANIMAL.h"
#include"CVEHICLE.h"
#include"CTRUCK.h"
#include"CCAR.h"
#include"CHORSE.h"
#include"CRABBIT.h"
#include"CTRAIN.h"

#include"CPEOPLE.h"
#include"CLANE.h"

struct Top {
	string name;
	short Level;
	long Score;
};

class CGAME {
private:
	CLANE<CANIMAL, CHORSE>* lane1 = new CLANE<CANIMAL, CHORSE>(sLEFT, HEIGHT_ROAD);
	CLANE<CANIMAL, CRABBIT>* lane2 = new CLANE<CANIMAL, CRABBIT>(sLEFT, 2 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CCAR>* lane3 = new CLANE<CVEHICLE, CCAR>(sLEFT, 3 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CCAR>* lane4 = new CLANE<CVEHICLE, CCAR>(sLEFT, 4 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CTRUCK>* lane5 = new CLANE<CVEHICLE, CTRUCK>(sLEFT, 5 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CTRUCK>* lane6 = new CLANE<CVEHICLE, CTRUCK>(sLEFT, 6 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CTRAIN>* laneTrain = new CLANE<CVEHICLE, CTRAIN>(sLEFT, 2 * HEIGHT_ROAD);
	
	vector<Top>hightScore;
	CPEOPLE people;
	string username;
	short currentLevel;
	unsigned short score;
	bool is_Running;
	
	short numCar;
	short numTruck;
	short numHorse;
	short numRabbit;
	bool isSound;
	bool isMusic;

	void clearGame();
	short randomColor(short, short);
	void saveGame(ofstream&);
	void loadGame(ifstream&);

public:
	CGAME();
	~CGAME();

	bool runApp(bool check = true);
	void drawGame();
	void resetGame(short level = 0);

	CPEOPLE* getPeople() { return &people; }
	vector<CANIMAL*> getHorses() const { return lane1->getListObjs(); }
	vector<CANIMAL*> getRabbits() const { return lane2->getListObjs(); }
	vector<CVEHICLE*> getCarLefts() const { return lane3->getListObjs(); }
	vector<CVEHICLE*> getCarRights() const { return lane4->getListObjs(); }
	vector<CVEHICLE*> getTruckLefts() const { return lane5->getListObjs(); }
	vector<CVEHICLE*> getTruckRights() const { return lane6->getListObjs(); }
	vector<CVEHICLE*> getTrain() const { return laneTrain->getListObjs(); }

	short getNumOfHorses() const { return numHorse; }
	short getNumOfRabbits() const { return numRabbit; }
	short getNumOfCars() const { return numCar; }
	short getNumOfTructs() const { return numTruck; }
	short getNumOfTrains() const { return laneTrain->getNumObjs(); }
	bool getSound() { return isSound; }
	bool getMusic() { return isMusic; }

	void setLevel(short);
	void updatePosVehicle();
	void updatePosAnimal();
	void updatePosPeople(short);
	void drawObjects(short);

	bool isRunning() const { return is_Running; };
	void pauseGame(thread* t = nullptr);
	void resumeGame(void (*f)() = nullptr, thread* t = nullptr);
	void startMusic();
	void MusicStatus(bool);
	void startGame();

	bool Win_nextLevel();
	bool Game_over();
	bool ESC();
	void Settings();
	void Save_game();
	void Load_game(bool&, string&);
	void Exit_game(thread* run = nullptr);

	// High Score
	void Input_HightScore(string);
	void Output_HightScore(string);
	void Insert();
	void displayTopHighScore(short);

	void drawGuide();
	void drawInforLevel();
	void drawAbout();

private:
	vector<vector<short>> rabbitLeft_1;
	vector<vector<short>> rabbitLeft_2;
	vector<vector<short>> rabbitRight_1;
	vector<vector<short>> rabbitRight_2;
	vector<vector<short>> horseLeft_1;
	vector<vector<short>> horseLeft_2;
	vector<vector<short>> horseRight_1;
	vector<vector<short>> horseRight_2;

	vector<vector<short>> truckFormRight1;
	vector<vector<short>> truckFormLeft2;
	vector<vector<short>> carFormLeft2;
	vector<vector<short>> carFormRight1;
	vector<vector<short>> trainFormLeft;
	vector<vector<short>> trainFormRight;

	vector<vector<short>> loadForm(string);
};
