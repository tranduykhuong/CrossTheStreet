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

#include"CPEOPLE.h"
#include"CLANE.h"

// Form Rabbit
static vector<vector<short>> rabbitLeft_1 =
{ {40,92,95,47,41,32}
, {40,39,126,39,41,32}
, {32,92,167,167,92,111}
, {32,32,32,111,111,32} };
static vector<vector<short>> rabbitLeft_2 =
{ {40, 92, 95, 47, 41, 32}
, { 40,39,126,39,41,32 }
, { 32,92,167,167,92,111 }
, { 32,111,111,32,32,32 } };
static vector<vector<short>> rabbitRight_1 =
{ {32,40,92,95,47,41}
, {32,40,39,126,39,41}
, {111,47,167,167,47,32}
, {32,111,111,32,32,32} };
static vector<vector<short>> rabbitRight_2 =
{ {32,40,92,95,47,41}
, {32,40,39,126,39,41}
, {111,47,167,167,47,32}
, {32,32,32,111,111,32} };

// Form Horse
static vector<vector<short>> horseLeft_1 =
{ {46,32,32,32,32,32}
, {60,41,32,32,32,32}
, {40,35,35,35,41,126}
, {179,179,32,179,179,32} };
static vector<vector<short>> horseLeft_2 =
{ {46,32,32,32,32,32}
, {60,41,32,32,32,32}
, {40,35,35,35,41,126}
, {32,92,92,32,92,92} };
static vector<vector<short>> horseRight_1 =
{ {32,32,32,32,32,46}
, {32,32,32,32,40,62}
, {126,40,35,35,35,41}
, {32,179,179,32,179,179} };
static vector<vector<short>> horseRight_2 =
{ {32,32,32,32,32,46}
, {32,32,32,32,40,62}
, {126,40,35,35,35,41}
, {47,47,32,47,47,32} };

// Form Truck
static vector<vector<short>> truckFormLeft1 =
{ {32,32,32,32,95,95,32,32,32,32,32,32,32,32,32,32,32,32}
, {32,95,95,47,95,95,179,95,95,95,95,95,95,95,95,95,95,47}
, {47,248,95,95,95,95,179,32,32,32,32,32,32,32,32,32,32,179}
, {96,45,40,15,41,45,45,45,45,45,45,45,40,15,41,45,45,39} };
static vector<vector<short>> truckFormRight1 =
{ {32,32,32,32,32,32,32,32,32,32,32,32,95,95,32,32,32,32}
, {92,95,95,95,95,95,95,95,95,95,95,179,95,95,92,95,95,32}
, {179,32,32,32,32,32,32,32,32,32,32,179,95,95,95,95,248,92}
, {96,45,45,40,15,41,45,45,45,45,45,45,45,40,15,41,45,39} };
static vector<vector<short>> truckFormLeft2 =
{ {32,32,32,32,95,95,32,95,95,95,95,95,95,95,95,95,95,32}
, {32,95,95,47,95,95,179,61,61,61,61,61,61,61,61,61,61,179}
, {47,248,95,95,95,95,179,95,95,95,95,95,95,95,95,95,95,179}
, {96,45,45,40,15,41,45,45,45,45,45,45,40,15,41,45,45,39} };
static vector<vector<short>> truckFormRight2 =
{ {32,95,95,95,95,95,95,95,95,95,95,32,95,95,32,32,32,32}
, {179,61,61,61,61,61,61,61,61,61,61,179,95,95,92,95,95,32}
, {179,95,95,95,95,95,95,95,95,95,95,179,95,95,95,95,248,92}
, {96,45,45,40,15,41,45,45,45,45,45,45,40,15,41,45,45,39} };

// Form Car
static vector<vector<short>> carFormLeft1 =
{ {32,32,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,32}
, {32,47,32,32,32,179,95,95,179,95,95,179,95,95,179,95,95,179}
, {179,248,95,95,179,32,32,32,32,32,32,32,32,32,32,32,32,179}
, {96,45,40,15,41,45,45,45,45,45,45,45,40,15,41,45,45,39} };
static vector<vector<short>> carFormRight1 =
{ {32,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,32,32}
, {179,95,95,179,95,95,179,95,95,179,95,95,179,32,32,32,92,32}
, {179,32,32,32,32,32,32,32,32,32,32,32,179,95,95,95,248,179}
, {96,45,45,40,15,41,45,45,45,45,45,45,45,40,15,41,45,39} };
static vector<vector<short>> carFormLeft2 =
{ {32,32,32,32,32,95,95,95,95,95,95,95,95,95,32,32,32,32}
, {32,95,95,95,47,95,95,179,95,95,179,95,95,95,92,95,95,32}
, {47,248,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,179}
, {96,45,45,40,15,41,45,45,45,45,45,45,40,15,41,45,45,39} };
static vector<vector<short>> carFormRight2 =
{ {32,32,32,32,95,95,95,95,95,95,95,95,95,32,32,32,32,32}
, {32,95,95,47,95,95,95,179,95,95,179,95,95,92,95,95,95,32}
, {179,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,248,92}
, {96,45,45,40,15,41,45,45,45,45,45,45,40,15,41,45,45,39} };


class CGAME {
private:
	CLANE<CANIMAL, CHORSE>* lane1 = new CLANE<CANIMAL, CHORSE>(sLEFT, HEIGHT_ROAD);
	CLANE<CANIMAL, CRABBIT>* lane2 = new CLANE<CANIMAL, CRABBIT>(sLEFT, 2 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CCAR>* lane3 = new CLANE<CVEHICLE, CCAR>(sLEFT, 3 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CCAR>* lane4 = new CLANE<CVEHICLE, CCAR>(sLEFT, 4 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CTRUCK>* lane5 = new CLANE<CVEHICLE, CTRUCK>(sLEFT, 5 * HEIGHT_ROAD);
	CLANE<CVEHICLE, CTRUCK>* lane6 = new CLANE<CVEHICLE, CTRUCK>(sLEFT, 6 * HEIGHT_ROAD);

	CPEOPLE people;

	bool is_Running;
	short currentLevel;

	short numCar;
	short numTruck;
	short numHorse;
	short numRabbit;

	void clearGame();
	short randomDistance(short, short, short, short);
	short randomDistance_RIGHT(short, short, short, short);
	short randomColor(short, short);

	bool isSound;
	bool isMusic;
public:
	CGAME();
	~CGAME() {};

	void runApp();
	void drawGame();
	void resetGame(short);
	void saveGame(fstream&);
	void loadGame(fstream&);

	CPEOPLE getPeople() const { return people; }
	vector<CANIMAL*> getHorses() const { return lane1->getListObjs(); }
	vector<CANIMAL*> getRabbits() const { return lane2->getListObjs(); }
	vector<CVEHICLE*> getCarLefts() const { return lane3->getListObjs(); }
	vector<CVEHICLE*> getCarRights() const { return lane4->getListObjs(); }
	vector<CVEHICLE*> getTruckLefts() const { return lane5->getListObjs(); }
	vector<CVEHICLE*> getTruckRights() const { return lane6->getListObjs(); }

	short getNumOfHorses() const { return numHorse; }
	short getNumOfRabbits() const { return numRabbit; }
	short getNumOfCars() const { return numCar; }
	short getNumOfTructs() const { return numTruck; }

	void updatePosVehicle();
	void updatePosAnimal();
	void updatePosPeople(short);
	void drawObjects(short);

	bool isRunning() const { return is_Running; };

	void drawGuide();

	bool getSound() { return isSound; }
};