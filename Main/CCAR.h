#pragma once
#include "CONSOLE.h"
#include "CVEHICLE.h"

class CCAR : public CVEHICLE
{
private:
	vector<vector<short>> form;

	short mMove;
	short countSpeed;
public:
	CCAR();
	CCAR(short, short, short, short, short);
	~CCAR();

	void set(short, short, short, short, short);
	void setForm(const vector<vector<short>>&, const vector<vector<short>>&);

	short getHeight() const;
	short getWidth() const;

	void move();
	void draw() const;
};