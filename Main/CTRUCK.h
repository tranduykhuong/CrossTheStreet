#pragma once
#include "CONSOLE.h"
#include "CVEHICLE.h"

class CTRUCK : public CVEHICLE
{
private:
	vector<vector<short>> form;

	short mMove;
	short countSpeed;
public:
	CTRUCK();
	CTRUCK(short, short, short, short, short);
	~CTRUCK();

	void set(short, short, short, short, short);
	void setForm(const vector<vector<short>>&, const vector<vector<short>>&);

	short getWidth() const;
	short getHeight() const;

	void move();
	void draw() const;
};

