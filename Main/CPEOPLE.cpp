#include "CPEOPLE.h"


CPEOPLE::CPEOPLE() {
	mX = (GameScreen::sLEFT + GameScreen::sRIGHT) / 2;
	mY = GameScreen::sBOTTOM - heightPeople;
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::blue;
}

CPEOPLE::CPEOPLE(short x, short y) {
	mX = x;
	mY = y;
	mState = true;
	mSpeed = 1;
	mColor = ColorGame::blue;
}

CPEOPLE::~CPEOPLE() {
	mX = 0;
	mY = 0;
	mState = false;
	mSpeed = 0;
	mColor = 0;
}

void CPEOPLE::up() {
	if (mY - heightRoad > GameScreen::sTOP)
		mY -= heightRoad;
}

void CPEOPLE::down() {
	if (mY + heightRoad < GameScreen::sBOTTOM)
		mY += heightRoad;
}

void CPEOPLE::left() {
	if (mX - mSpeed > GameScreen::sLEFT)
		mX -= mSpeed;
}

void CPEOPLE::right() {
	if (mX + mSpeed + widthPeople < GameScreen::sRIGHT)
		mX += mSpeed;
}

void CPEOPLE::setState(bool state) {
	mState = state;
}

void CPEOPLE::setPosition(short x, short y) {
	if (x<GameScreen::sRIGHT && x>GameScreen::sLEFT)
		mX = x;
	if (y + heightPeople >= GameScreen::sBOTTOM && y + heightPeople - heightRoad >= GameScreen::sTOP)
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

	for (int i = 0; i < heightPeople; i++) {
		CONSOLE::gotoXY(mX, mY + i);
		for (int j = 0; j < widthPeople; j++)
			cout << char(form[i][j]);
	}
}