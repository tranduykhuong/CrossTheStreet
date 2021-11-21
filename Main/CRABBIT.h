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

	void set(const short&, const short&, const short&, const short&, const short&);
	void setForm(const vector<vector<short>>&, const vector<vector<short>>&);
	short getHeight() const;
	short getWidth() const;

	void tell();
	void move();
	void draw() const;
};