#include<string>
#include <sstream>
#include "Commercial.h"
#include "Property.h"
#pragma once

using namespace std;

Commercial::Commercial(bool rentalIN, int valueIN, bool discountStautsIN, double discountRateIN, string addressIN) : Property(rental, value, address)
{
	discountStatus = discountStautsIN;
	discountRate = discountRateIN;
}
bool Commercial::getDiscountStatus()
{
	return discountStatus;
}
double Commercial::getDiscountRate()
{
	return discountRate;
}
double Commercial::getTax()
{
	double taxRate = 0;
	if (rental == 1){
		taxRate = .012;
	}
	else{
		taxRate = .01;
	}
	if (discountStatus == 1){
		tax = taxRate* (value * (1 - discountRate));
	}
	else{
		tax = value * taxRate;
	}
	return tax;
}
string Commercial::toString()
{
	string RENTAL;
	if (rental == 1){
		RENTAL = "Rental ";
	}
	else{
		RENTAL = "NOT A RENTAL ";
	}
	string DISCOUNT_STATUS;
	if (discountStatus == 1){
		DISCOUNT_STATUS = "Discounted ";
	}
	else{
		DISCOUNT_STATUS = "Not Discounted ";
	}
	stringstream ss;
	ss << "Property ID: " << ID << "  " << "Address: " << address << "  " << RENTAL << "  " << "Estimated value: " << value << "  " << DISCOUNT_STATUS << "  " << "Discounted: " << discountRate << endl;
	return ss.str();
}
