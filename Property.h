#include<string>
#include<sstream>
#pragma once 

using namespace std;

class Property
{
public:
	Property::Property(bool rental, int value, string address);
	~Property();
	bool getRental();
	int getValue();
	string getAddress();
	virtual double getTax();
	int getID() const; 
	virtual string toString();
	int ID = 0;

protected:
	bool rental;
	int value;
	string address;
	double tax;
	
};
