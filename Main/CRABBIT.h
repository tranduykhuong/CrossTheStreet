#pragma once
#include "CANIMAL.h"

class CRABBIT : public CANIMAL
{
	vector<vector<char>> rabbitLeft_1 = {	{'(' ,'\\' ,'_','/',')',' '},
											{'(','\'','~','\'',')',' '},
											{' ','\\',char(167),char(167),'\\','o'},
											{' ',' ',' ','o','o',' '}
	};
	vector<vector<char>> rabbitLeft_2 = {	{'(' ,'\\' ,'_','/',')',' '},
											{'(','\'','~','\'',')',' '},
											{' ','\\',char(167),char(167),'\\','o'},
											{' ','o','o',' ',' ',' '}
	};

	vector<vector<char>> rabbitRight_1 = {	{' ','(' ,'\\' ,'_','/',')'},
											{' ','(','\'','~','\'',')'},
											{'o','/',char(167),char(167),'/',' '},
											{' ','o','o',' ',' ',' '}
	};
	vector<vector<char>> rabbitRight_2 = { {' ','(' ,'\\' ,'_','/',')'},
											{' ','(','\'','~','\'',')'},
											{'o','/',char(167),char(167),'/',' '},
											{' ',' ',' ','o','o',' '}
	};

	short mMove;
public:
	CRABBIT();
	~CRABBIT();

	void set(const short&, const short&, const int&, const short&, const short&);
	int getHeight();
	int getWidth();

	const vector<vector<char>>& getDraw(const int&);
	void tell();
	void move();
};

