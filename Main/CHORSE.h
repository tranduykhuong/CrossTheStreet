#pragma once
#include "CANIMAL.h"
class CHORSE : public CANIMAL
{
	vector<vector<short>> form1;
	vector<vector<short>> form2;

	//short mMove;
	short countSpeed;
public:
	CHORSE();
	CHORSE(const CHORSE&);
	CHORSE(const short&, const short&, const short&, const short&, const short&);
	~CHORSE();

	void set(const short&, const short&, const short&, const short&, const short&);
	void setForm(const vector<vector<short>>&, const vector<vector<short>>&);
	short getHeight() const;
	short getWidth() const;

	void tell();
	void move();
	void draw() const;
};