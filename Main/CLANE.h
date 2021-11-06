#pragma once
#include"CONSOLE.h"

template<class T, class U>
class CLANE {
	vector<T*> listObjs;

	short X, Y;

	short randomColor(short, short); 
	short randomDistance(short, short, short, short);
public:
	CLANE(short, short);
	~CLANE();

	void setLane(short, short, short, const vector<vector<short>>, const vector<vector<short>>);
	vector<T*> getListObjs() { return listObjs; }
	void drawObj() const;
	void moveObj();
	void clearObjs();
};

template<class T, class U>
CLANE<T, U>::CLANE(short x, short y)
{
	X = x;
	Y = y;
}

template<class T, class U>
CLANE<T, U>::~CLANE()
{
	clearObjs();
}

// Lấy màu ngẫu nhiên
template<class T, class U>
short CLANE<T, U>::randomColor(short start, short end)
{
	while (1) {
		int ran = rand() % (end - start + 1) + start;
		if (ran >= start && ran <= end)
			return ran;
	}
}

// Lấy khoảng cách ngẫu nhiên so với đối tượng phía trước
template<class T, class U>
short CLANE<T, U>::randomDistance(short x_before, short num, short widthObs, short screenRight)
{
	short delta = num * (widthObs + 3);
	while (1) {
		int ran = rand() % 40 + 3;
		if (x_before + ran + 2 * widthObs + delta + 2 < screenRight)
			return ran;
	}
}

/// <summary>
/// Set các đối tượng trên Lane
/// ---------------------------
///		num		: số lượng objects
///		speed   : vận tốc của mỗi object
///		move	: di chuyển sang phải hoặc trái
///		form1	: ma trận hình dáng 1 của đối tượng
///		form2	: ma trận hình dáng 2 của đối tượng (nếu có)
/// </summary>
template<class T, class U>
void CLANE<T, U>::setLane(short num, short speed, short move, 
	const vector<vector<short>> form1, const vector<vector<short>> form2)
{
	short heightObj = form1.size();
	short widthObj = form1[0].size();

	for (short i = 0; i < num; i++) {
		// set Object đầu tiên trong mảng
		if (i == 0) { 
			// xe đi sang trái
			if (move == LEFT) {
				listObjs.push_back(new U(sRIGHT + 1, Y + HEIGHT_ROAD - heightObj,
					randomColor(ColorGame::black, ColorGame::olive), speed, LEFT));
				listObjs[i]->setForm(form1, form2);
			}
			// xe đi sang phải
			else {
				listObjs.push_back(new U(sLEFT - widthObj, Y + HEIGHT_ROAD - heightObj,
					randomColor(ColorGame::black, ColorGame::olive), speed, RIGHT));
				listObjs[i]->setForm(form1, form2);
			}
		}
		// set các Object còn lại dựa theo tọa độ Car đầu tiên
		else {		  
			// lấy tọa độ x của Obj phía trước
			short before_x = listObjs[i - 1]->getX();

			// set cho các xe còn lại
				// xe đi sang phải
			if (move == LEFT) {
				// lấy khoảng các ngẫu nhiên so với xe trước
				short distance = randomDistance(before_x, num - i - 1, widthObj, sRIGHT + SCREEN_GAME_WIDTH);

				// Push object vào listObjs
				listObjs.push_back(new U(before_x + distance + widthObj, Y + HEIGHT_ROAD - heightObj,
					randomColor(ColorGame::black, ColorGame::olive), speed, LEFT));
				listObjs[i]->setForm(form1, form2);
			}
				// xe đi sang trái
			else {
				// lấy khoảng các ngẫu nhiên so với xe trước
				short distance = randomDistance(-(before_x + widthObj), num - i - 1, widthObj, -(sLEFT - SCREEN_GAME_WIDTH));
				
				// Push object vào listObjs
				listObjs.push_back(new U(listObjs[i - 1]->getX() - widthObj - distance, Y + HEIGHT_ROAD - heightObj,
					randomColor(ColorGame::black, ColorGame::olive), speed, RIGHT));
				listObjs[i]->setForm(form1, form2);
			}
		}
	}
}

// Draw các đối tượng trong listObjs
template<class T, class U>
void CLANE<T, U>::drawObj() const
{
	short num = listObjs.size();
	for (short i = 0; i < num; i++)
		listObjs[i]->draw();
}

// Move các đối tượng trong listObjs
template<class T, class U>
void CLANE<T, U>::moveObj()
{
	short num = listObjs.size();
	for (short i = 0; i < num; i++)
		listObjs[i]->move();
}

// Remove các đối tượng trong listObjs
template<class T, class U>
void CLANE<T, U>::clearObjs()
{
	short num = listObjs.size();
	for (short i = 0; i < num; i++) {
		delete listObjs[i];
		listObjs[i] = NULL;
	}
	listObjs.clear();
}
