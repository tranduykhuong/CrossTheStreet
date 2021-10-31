#pragma once
#include "CANIMAL.h"
class CHORSE : public CANIMAL
{
	vector<vector<char>> horseLeft_1 = { {'.',' ',' ',' ',' ',' '},
											{'<',')',' ',' ',' ',' '},
											{'(','#','#','#',')','~'},
											{'|','|',' ','|','|',' '}
	};
	vector<vector<char>> horseLeft_2 = { {'.',' ',' ',' ',' ',' '},
											{'<',')',' ',' ',' ',' '},
											{'(','#','#','#',')','~'},
											{' ','\\','\\',' ','\\','\\'}
	};

	vector<vector<char>> horseRight_1 = { {' ',' ',' ',' ',' ','.'},
											{' ',' ',' ',' ','(','>'},
											{'~','(','#','#','#',')'},
											{' ','|','|',' ','|','|'}
	};
	vector<vector<char>> horseRight_2 = { {' ',' ',' ',' ',' ','.'},
											{' ',' ',' ',' ','(','>'},
											{'~','(','#','#','#',')'},
											{'/','/',' ','/','/',' '}
	};

	short mMove;
	short countSpeed;
public:
	CHORSE();
	~CHORSE();

	void set(const short&, const short&, const int&, const short&, const short&);
	int getHeight();
	int getWidth();

	void tell();
	void move();
	void draw();
};