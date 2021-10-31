#pragma once
#include"CONSOLE.h"
#include"CDRAW.h"
#include"CMENU.h"

#include"CTRUCK.h"
#include"CCAR.h"
#include"CHORSE.h"
#include"CRABBIT.h"

#include"CPEOPLE.h"

class CGAME {
private:
	CCAR* carLeft;
	CCAR* carRight;
	CTRUCK* truckLeft;
	CTRUCK* truckRight;
	CHORSE* horse;
	CRABBIT* rabbit;

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
public:
	CGAME();

	void runApp();
	void drawGame();
	void resetGame(short);

	CPEOPLE getPeople();

	void updatePosVehicle();
	void updatePosAnimal();
	void updatePosPeople(short);
	void drawObjects(short);

	bool isRunning() const { return is_Running; };

	void drawGuide();
};