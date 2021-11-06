#include "CPEOPLE.h"

vector<vector<short>> CPEOPLE::peopleWait = { {32, 2, 32}, {47, 245, 92}, {47, 32, 92} };
vector<vector<short>> CPEOPLE::peopleUp = { {92, 2, 47}, {32, 245, 32}, {47, 32, 92} };
vector<vector<short>> CPEOPLE::peopleLeft = { {92, 2, 32}, {32, 245, 92}, {124, 32, 92} };
vector<vector<short>> CPEOPLE::peopleRight = { {32, 2, 47}, {47, 245, 32}, {47, 32, 124} };
vector<vector<short>> CPEOPLE::peopleDown = { {92, 2, 47}, {32, 245, 32}, {60, 32, 62} };
vector<vector<int>> CPEOPLE::peopleShade = { {32,32,32},{32,32,32},{32,32,32} };

CPEOPLE::CPEOPLE() {
	mX = (GameScreen::sLEFT + GameScreen::sRIGHT) / 2;
	mY = GameScreen::sBOTTOM - getHeightPeople();
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::green;
	colorShade = ColorGame::black;
}

CPEOPLE::CPEOPLE(short x, short y) {
	mX = x;
	mY = y;
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::blue;
	colorShade = ColorGame::black;
}

void CPEOPLE::up() {
	if (mY - mSpeed > GameScreen::sTOP)
		mY -= mSpeed;
}

void CPEOPLE::down() {
	if (mY + mSpeed + getHeightPeople() - 1 < GameScreen::sBOTTOM)
		mY += mSpeed;
}

void CPEOPLE::left() {
	if (mX - mSpeed > GameScreen::sLEFT)
		mX -= mSpeed;
}

void CPEOPLE::right() {
	if (mX + mSpeed + getWidthPeople() - 1 < GameScreen::sRIGHT)
		mX += mSpeed;
}

void CPEOPLE::setState(bool state) {
	mState = state;
}

void CPEOPLE::setPosition(short x, short y) {
	if (x<GameScreen::sRIGHT && x>GameScreen::sLEFT)
		mX = x;
	if (y + getHeightPeople() >= GameScreen::sBOTTOM && y + getHeightPeople() - HEIGHT_ROAD >= GameScreen::sTOP)
		mY = y;
}

void CPEOPLE::setSpeed(short speed) {
	if (speed >= 0)
		mSpeed = speed;
}

void CPEOPLE::setColor(int newColor) {
	if (newColor >= 0 && newColor < 256)
		mColor = newColor;
}

void CPEOPLE::setColorShade(int newColorShade) {
	if (newColorShade >= 0 && newColorShade < 256)
		colorShade = newColorShade;
}

short CPEOPLE::getSpeed() const {
	return mSpeed;
}

short CPEOPLE::getX() const {
	return mX;
}

short CPEOPLE::getY() const {
	return mY;
}

int CPEOPLE::getColor() const {
	return mColor;
}

int CPEOPLE::getColorShade() const {
	return colorShade;
}

bool CPEOPLE::isDead() const {
	return mState == false;
}

bool CPEOPLE::isWin() const {
	return mY < (GameScreen::sTOP + HEIGHT_ROAD);
}

void CPEOPLE::draw(int key) {
	vector<vector<short>> form;
	CONSOLE::textcolor(colorShade);

	switch (key) {
	case Key::UP: {
		form = peopleUp;

		vector<int> shade;
		for (int i = 0; i < getWidthPeople(); i++)
			shade.push_back(CONSOLE::getConsoleCharacter(mX + i, mY));
		peopleShade.insert(peopleShade.begin(), shade);

		CONSOLE::gotoXY(mX, mY + getHeightPeople());
		for (auto e : peopleShade[getHeightPeople()])
			cout << (char)e;
		peopleShade.erase(peopleShade.begin() + getHeightPeople());

		break;
	}
	case Key::DOWN: {
		form = peopleDown;

		vector<int> shade;
		for (int i = 0; i < getWidthPeople(); i++)
			shade.push_back(CONSOLE::getConsoleCharacter(mX + i, mY + getHeightPeople() - 1));
		peopleShade.push_back(shade);

		CONSOLE::gotoXY(mX, mY - 1);
		for (auto e : peopleShade[0])
			cout << char(e);
		peopleShade.erase(peopleShade.begin());

		break;
	}
	case Key::LEFT: {
		form = peopleLeft;

		for (int i = 0; i < getHeightPeople(); i++) {
			CONSOLE::gotoXY(mX + getWidthPeople(), mY + i);
			cout << char(peopleShade[i][getWidthPeople() - 1]);
		}

		for (int i = 0; i < getHeightPeople(); i++) {
			vector<int> shade = peopleShade[i];
			shade.erase(shade.begin() + shade.size() - 1);
			shade.insert(shade.begin(), CONSOLE::getConsoleCharacter(mX, mY + i));

			peopleShade[i] = shade;
		}

		break;
	}
	case Key::RIGHT: {
		form = peopleRight;

		for (int i = 0; i < getHeightPeople(); i++) {
			CONSOLE::gotoXY(mX - 1, mY + i);
			cout << char(peopleShade[i][0]);
		}

		for (int i = 0; i < getHeightPeople(); i++) {
			vector<int> shade = peopleShade[i];
			shade.erase(shade.begin());
			shade.push_back(CONSOLE::getConsoleCharacter(mX + getWidthPeople() - 1, mY + i));

			peopleShade[i] = shade;
		}
		break;
	}
	default: {
		form = peopleWait;
		break;
	}
	}

	CONSOLE::textcolor(mColor);
	for (int i = 0; i < getHeightPeople(); i++) {
		CONSOLE::gotoXY(mX, mY + i);
		for (int j = 0; j < getWidthPeople(); j++)
			cout << char(form[i][j]);
	}
}

bool CPEOPLE::isImpact(const vector<CVEHICLE*>& objs, short n) {
	// Lấy tọa độ people
	short L = mX;
	short R = mX + getWidthPeople();
	short T = mY;
	short B = mY + getHeightPeople();

	for (int i = 0; i < n; i++) {
		// Lấy tạo độ object
		short l = objs[i]->getX();
		short r = objs[i]->getX() + objs[i]->getWidth();
		short t = objs[i]->getY();
		short b = objs[i]->getY() + objs[i]->getHeight();

		// Va chạm cạnh trên của object với people
		if (B > t && B < b) {
			if ((R > l && R < r) || (L < r && L > l))
				return true;
		}

		// Va chạm cạnh dưới của object với people
		if (T < b && T > t) {
			if ((R > l && R < r) || (L > l && L < r))
				return true;
		}
	}
	return false;
}

bool CPEOPLE::isImpact(const vector<CANIMAL*>& objs, short n) {
	// Lấy tọa độ people
	short L = mX;
	short R = mX + getWidthPeople();
	short T = mY;
	short B = mY + getHeightPeople();

	for (int i = 0; i < n; i++) {
		// Lấy tạo độ object
		short l = objs[i]->getX();
		short r = objs[i]->getX() + objs[i]->getWidth();
		short t = objs[i]->getY();
		short b = objs[i]->getY() + objs[i]->getHeight();

		// Va chạm cạnh trên của object với people
		if (B > t && B < b) {
			if ((R > l && R < r) || (L < r && L > l))
				return true;
		}

		// Va chạm cạnh dưới của object với people
		if (T < b && T > t) {
			if ((R > l && R < r) || (L > l && L < r))
				return true;
		}
	}
	return false;
}