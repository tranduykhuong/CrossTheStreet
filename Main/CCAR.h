#pragma once
#include "CONSOLE.h"
#include "CVEHICLE.h"

class CCAR : public CVEHICLE
{
private:
	vector<vector<short>> form;

	short countSpeed;
public:
	CCAR();
	CCAR(const CCAR&);
	CCAR(const short&, const short&, const short&, const short&, const short&);
	~CCAR();

	void set(const short&, const short&, const short&, const short&, const short&);
	void setForm(const vector<vector<short>>&, const vector<vector<short>>&);

	short getHeight() const;
	short getWidth() const;

	void move();
	void draw() const;
};