#pragma once
#include "CANIMAL.h"
class CHORSE : public CANIMAL
{
	vector<vector<short>> form1;
	vector<vector<short>> form2;

	short countSpeed;
public:
	CHORSE();
	CHORSE(const CHORSE&);
	CHORSE(const short&, const short&, const short&, const short&, const short&);
	~CHORSE();

	virtual void set(const short&, const short&, const short&, const short&, const short&);
	virtual void setForm(const vector<vector<short>>&, const vector<vector<short>>&);
	virtual short getHeight() const;
	virtual short getWidth() const;

	virtual void tell();
	virtual void move();
	virtual void draw() const;
};