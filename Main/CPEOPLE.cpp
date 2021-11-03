#include "CPEOPLE.h"


CPEOPLE::CPEOPLE() {
	mX = (GameScreen::sLEFT + GameScreen::sRIGHT) / 2;
	mY = GameScreen::sBOTTOM - getHeightPeople();
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::green;
	colorShade = ColorGame::navi;
}

CPEOPLE::CPEOPLE(short x, short y) {
	mX = x;
	mY = y;
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::blue;
	colorShade = ColorGame::navi;
}

bool CPEOPLE::up() {
	if (mY - mSpeed > GameScreen::sTOP) {
		mY -= mSpeed;
		return true;
	}
	return false;

}

bool CPEOPLE::down() {
	if (mY + mSpeed + getHeightPeople() - 1 < GameScreen::sBOTTOM) {
		mY += mSpeed;
		return true;
	}
	return false;
}

bool CPEOPLE::left() {
	if (mX - mSpeed > GameScreen::sLEFT) {
		mX -= mSpeed;
		return true;
	}
	return false;
}

bool CPEOPLE::right() {
	if (mX + mSpeed + getWidthPeople() - 1 < GameScreen::sRIGHT) {
		mX += mSpeed;
		return true;
	}
	return false;
}

void CPEOPLE::setState(bool state) {
	mState = state;
}

void CPEOPLE::setPosition(short x, short y) {
	if (x<GameScreen::sRIGHT && x>GameScreen::sLEFT)
		mX = x;
	if (y + getHeightPeople() >= GameScreen::sBOTTOM && y + getHeightPeople() - heightRoad >= GameScreen::sTOP)
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
	return mY < (GameScreen::sTOP + heightRoad);
}

void CPEOPLE::draw(int key) {
	vector<vector<int>> form;
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