#pragma once
#include "CANIMAL.h"

class CRABBIT : public CANIMAL
{
	vector<vector<short>> form1;
	vector<vector<short>> form2;

	short countSpeed;
public:
	CRABBIT();
	CRABBIT(const CRABBIT&);
	CRABBIT(const short&, const short&, const short&, const short&, const short&);
	~CRABBIT();

	virtual void set(const short&, const short&, const short&, const short&, const short&);
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&);
	virtual short getHeight() const;
	virtual short getWidth() const;

	virtual void tell();
	virtual void move();
	virtual void draw() const;
};