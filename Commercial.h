#include<sstream>
#include<string>
#include "Property.h"
#pragma once
using namespace std;

class Commercial : public Property
{
public:
	Commercial::Commercial(bool rental, int value, bool discountStauts, double discountRate, string address);
	~Commercial();
	bool getDiscountStatus();
	double getDiscountRate();
	virtual double getTax();
	virtual string toString();
private:
	bool discountStatus;
	double discountRate;
};
