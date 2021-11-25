#pragma once
#include"CONSOLE.h"
#include "CTRAFFIC_LIGHT.h"

template<class T, class U>
class CLANE {
	vector<T*> listObjs;

	short X, Y;

	int countTimer;
	int actionSpeed;
	int stopSpeed;

	CTRAFFIC_LIGHT light;

	short randomColor(short, short);
	short randomDistance(short, short, short, short);
public:
	CLANE(short, short);
	~CLANE();

	void setTimerLight(int newActionSpeed, int newStopSpeed);
	void setLightColor(const int& color) {
		light.setLight(color);
	}
	void tellObj();

	void pushObj(const short&, const short&, const short&, const short&, const short&, const vector<vector<short>>&, const vector<vector<short>>&);
	void setLane(const short&, const short&, const short&, const vector<vector<short>>&, const vector<vector<short>>&);
	vector<T*> getListObjs() { return listObjs; }
	short getNumObjs() const { return listObjs.size(); }

	void drawObj() const;
	void moveObj();
	void clearObjs();
};

template<class T, class U>
CLANE<T, U>::CLANE(short x, short y)
{
	X = x;
	Y = y;
	countTimer = 1;
	actionSpeed = -1;
	stopSpeed = -1;
}

template<class T, class U>
CLANE<T, U>::~CLANE()
{
	clearObjs();
}

template<class T, class U>
inline void CLANE<T, U>::setTimerLight(int newActionSpeed, int newStopSpeed)
{
	if (listObjs[0]->getMove() == RIGHT)
		light.drawLight(sRIGHT + 1, Y + HEIGHT_ROAD - 3);
	else
		light.drawLight(sLEFT - 4, Y + HEIGHT_ROAD - 3);

	actionSpeed = newActionSpeed;
	stopSpeed = newStopSpeed;
}

// Lấy màu ngẫu nhiên
template<class T, class U>
inline short CLANE<T, U>::randomColor(short start, short end)
{
	while (1) {
		int ran = rand() % (end - start + 1) + start;
		if (ran >= start && ran <= end)
			return ran;
	}
}

// Lấy khoảng cách ngẫu nhiên so với đối tượng phía trước
template<class T, class U>
inline short CLANE<T, U>::randomDistance(short x_before, short num, short widthObs, short screenRight)
{
	short delta = num * (widthObs + 3);
	while (1) {
		int ran = rand() % 40 + 3;
		if (x_before + ran + 2 * widthObs + delta + 2 < screenRight)
			return ran;
	}
}

// Thêm 1 object vào danh sách
template<class T, class U>
inline void CLANE<T, U>::pushObj(const short& mX, const short& mY, const short& mColor,
	const short& mMove, const short& mSpeed, const vector<vector<short>>& form1, const vector<vector<short>>& form2)
{
	listObjs.push_back(new U(mX, mY, mColor, mSpeed, mMove));
	listObjs[listObjs.size() - 1]->setForm(form1, form2);
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
inline void CLANE<T, U>::setLane
(const short& num, const short& speed, const short& move, const vector<vector<short>>& form1, const vector<vector<short>>& form2)
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

// tell object
template<class T, class U>
inline void CLANE<T, U>::tellObj()
{
	if (listObjs.size() > 0)
		if (rand() % 500 == 0)
			listObjs[0]->tell();
}

// Draw các đối tượng trong listObjs
template<class T, class U>
inline void CLANE<T, U>::drawObj() const
{
	short num = listObjs.size();
	for (short i = 0; i < num; i++)
		listObjs[i]->draw();
}

// Move các đối tượng trong listObjs
template<class T, class U>
inline void CLANE<T, U>::moveObj()
{
	if (light.getLightColor() == 1) {
		short num = listObjs.size();

		for (short i = 0; i < num; i++)
			listObjs[i]->move();
		if (countTimer == actionSpeed) {
			countTimer = 1;
			light.setLightColor(0);
		}
		else
			if (actionSpeed != -1)
				countTimer++;
	}
	else {
		if (countTimer == stopSpeed) {
			countTimer = 1;
			light.setLightColor(1);
		}
		else
			if (actionSpeed != -1)
				countTimer++;
	}
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
