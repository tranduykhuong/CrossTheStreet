#pragma once
#include "CONSOLE.h"
#include "CVEHICLE.h"

class CTRUCK : public CVEHICLE
{
private:
	vector<vector<short>> form;

	short countSpeed;
public:
	CTRUCK();
	CTRUCK(const CTRUCK&);
	CTRUCK(const short&, const short&, const short&, const short&, const short&);
	~CTRUCK();

	void set(const short&, const short&, const short&, const short&, const short&);
	void setForm(const vector<vector<short>>&, const vector<vector<short>>&);

	short getWidth() const;
	short getHeight() const;

	void move();
	void draw() const;
};

