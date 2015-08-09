#include<sstream>
#include<string>
#include "Property.h"

using namespace std;

Property::Property(bool rentalIn, int valueIn, string addressIn)
{
	rental = rentalIn;
	value = valueIn;
	address = addressIn;
}
Property:: ~Property(){}
bool Property::getRental()
{
	return rental;
}
int Property::getValue()
{
	return value;
}
string Property::getAddress()
{
	return address;
}
double Property::getTax()
{
	return tax;
}
int Property::getID() const
{
	return ID;
}
string Property::toString()
{
	string RENTAL;
	if (rental == 0){
		RENTAL = "Not a Rental ";
	}
	else{
		RENTAL = "Rental ";
	}
	stringstream ss;
	ss << "Property ID: " << ID << "\t" << "Address: " << address << "t" << RENTAL << "\t" << "Estimated Value: " << value << endl;
	return ss.str();
}
