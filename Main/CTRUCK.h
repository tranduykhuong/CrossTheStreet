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

	virtual void set(const short&, const short&, const short&, const short&, const short&);
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&);

	virtual short getWidth() const;
	virtual short getHeight() const;

	virtual void move();
	virtual void draw() const;
	virtual void tell() const;
};

