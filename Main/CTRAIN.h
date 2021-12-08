#pragma once
#include "CONSOLE.h"
#include "CVEHICLE.h"

class CTRAIN : public CVEHICLE
{
private:
	vector<vector<short>> form;

	short countSpeed;

public:
	CTRAIN();
	CTRAIN(const CTRAIN&);
	CTRAIN(const short&, const short&, const short&, const short&, const short&);
	~CTRAIN();

	virtual void set(const short&, const short&, const short&, const short&, const short&);
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&);

	virtual short getHeight() const;
	virtual short getWidth() const;

	virtual void move();
	virtual void draw() const;
	virtual void tell() const;
};