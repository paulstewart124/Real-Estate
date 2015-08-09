#include "Property.h"
#include<sstream>
#include<string>
#pragma once
using namespace std;

class Residential : public Property
{
public: 
	Residential::Residential(bool rental, int value, bool occupied, string address);
	~Residential();
	bool getOccupied();
	virtual double getTax();
	virtual string toString();
private:
	bool occupied;
};
