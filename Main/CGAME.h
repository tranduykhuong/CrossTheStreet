#pragma once
#include"CONSOLE.h"
#include"CDRAW.h"
#include"CMENU.h"

class CGAME {
public:
	static SHORT MAX_LEVEL;
	
private:

public:
	CGAME();

	void runApp();
	void drawGame();
	void drawGuide();
};