#include "CPEOPLE.h"


CPEOPLE::CPEOPLE() {
	mX = (GameScreen::sLEFT + GameScreen::sRIGHT) / 2;
	mY = GameScreen::sBOTTOM - getHeightPeople();
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::green;
}

CPEOPLE::CPEOPLE(short x, short y) {
	mX = x;
	mY = y;
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::blue;
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

bool CPEOPLE::isDead() const {
	return mState == false;
}

bool CPEOPLE::isWin() const {
	return mY < (GameScreen::sTOP + heightRoad);
}

void CPEOPLE::draw(int key) {
	vector<vector<int>> form;
	CONSOLE::textcolor(mColor);

	switch (key) {
	case Key::UP:
		form = peopleUp;
		break;
	case Key::DOWN:
		form = peopleDown;
		break;
	case Key::LEFT:
		form = peopleLeft;
		break;
	case Key::RIGHT:
		form = peopleRight;
		break;
	default:
		form = peopleWait;
		break;
	}

	for (int i = 0; i < getHeightPeople(); i++) {
		CONSOLE::gotoXY(mX, mY + i);
		for (int j = 0; j < getWidthPeople(); j++)
			cout << char(form[i][j]);
	}
}