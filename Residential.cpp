#include<string>
#include<sstream>
#include "Property.h"
#include "Residential.h"

using namespace std;

Residential::Residential(bool rentalIN, int valueIN, bool occupiedIN, string addressIN) : Property(rental, value, address)
{
	occupied = occupiedIN;
}
Residential::~Residential(){}
bool Residential::getOccupied()
{
	return occupied;
}
double Residential::getTax()
{
	double TaxRate;
	if (occupied == 1){
		TaxRate = .006;
	}
	else{
		TaxRate = .009;
	}
	return TaxRate;
}
string Residential::toString()
{  
	string RENTAL;
	if (rental == 1){
		RENTAL = "Rental ";
	}
	else{
		RENTAL = "Not a Rental ";
	}

	string OCCUPIED;
	if (occupied == 1){
		OCCUPIED = "Occupied ";
	}
	else{
		OCCUPIED = " Not occupied ";
	}

	stringstream ss;
	ss << "Property ID: " << ID << "  " << "Address: " << address << "  " << "Estimated Valuee " << value << "  " << OCCUPIED << endl;
	return ss.str();
}
