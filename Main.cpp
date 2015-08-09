#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<iomanip>
#include "Property.h"
#include"Commercial.h"
#include"Residential.h"

using namespace std;

void Display(vector<Property*> allProperties)
{
	cout << "All valid properties:" << endl;
	for (int i = 0; i < allProperties.size(); i++){
		cout << allProperties[i]->toString();
		cout << endl;
	}
}
/*
I beleive that all my classes are set up corrrectly, I believe that problem is somewhere in this function load file
Property1.txt is the file that needs to be loaded.
*/
void loadFile(vector<Property*> &allProperties)
{	
	int ID = 0;
	cout << "Please enter the file name: " << endl;
	string fileName;
	cin >> fileName;
	ifstream inFile;
	
	inFile.open(fileName.c_str());

	if (inFile.fail()){
		cout << "File: " << fileName << " Does not exist. " << endl;
		system("pause");
		exit(EXIT_FAILURE);


	}
	if (!inFile.fail()){


		string line;
		while (getline(inFile, line)){
			stringstream inLine(line);
			string type;
			bool rental;
			int value;
			bool occupied;
			bool discountStatus;
			double discountRate;
			string address;

			if (inLine >> type){
				if (type == "Residential"){
					if (inLine >> rental >> value >> occupied && getline(inLine, address)){
						Property * r = new Residential(rental, value, occupied, address);
						allProperties.push_back(r);
						r->getID();
						ID++;
					}
					else{
						cout << "Ignoring bad Residential in input file:" << inLine.str() << endl;
					}
				}
				if (type == "Commercial"){
					if (inLine >> rental >> value >> discountStatus >> discountRate && getline(inLine, address)){
						Property* c = new Commercial(rental, value, discountStatus, discountRate, address);
						allProperties.push_back(c);
						c->getID();
						ID++;
					}
					else{
						cout << "Ignoring bad Commercial in input file: " << inLine.str() << endl;
					}
				}
				else{
					cout << "Ignoring unknown types of properties appearing in input fils: " << inLine.str() << endl;
				}
			}
		}
		inFile.close();
	}

}
void taxReport(vector<Property*> allProperties)
{
	cout << "**********************************************Now printing Tax Report*************************************************" << endl << endl;
	for (int i = 0; i < allProperties.size(); i++){
		cout << "Taxes due for the property at:  \t " << allProperties[i]->getAddress() << endl;
		cout << "Property ID: \t\t\t\t\t" << allProperties[i]->getID() << endl;
		cout << "This property has an estimated value of: \t\t" << allProperties[i]->getValue() << endl;
		cout << "Taxes due on this property are: \t\t\t" << allProperties[i]->getTax() << endl;
	}
}

int main()
{
	vector<Property*> allProperties;
	
	loadFile(allProperties);
	Display(allProperties);
	taxReport(allProperties);
	system("pause");
	return 0;
}
