#include "Vehicle.h"
#include<iostream>
#include<sstream>
using namespace std;

Vehicle::Vehicle()
{
	vehicleID = "";
	customerID = "";
	make = "";
	model = "";
	year = "";
	regNo = "";
	color = "";
}

Vehicle::Vehicle(string vid, string cid, string mk, string mdl, string yr, string reg, string col)
{
	vehicleID = vid;
	customerID = cid;
	make = mk;
	model = mdl;
	year = yr;
	regNo = reg;
	color = col;
}

string Vehicle::getVehicleID()
{
	return vehicleID;
}
string Vehicle::getCustomerID()
{
	return customerID;
}
string Vehicle::getMake()
{
	return make;
}
string Vehicle::getModel()
{
	return model;
}
string Vehicle::getYear()
{
	return year;
}
string Vehicle::getRegNo()
{
	return regNo;
}
string Vehicle::getColor()
{
	return color;
}

void Vehicle::setMake(string mk)
{
	make = mk;
}
void Vehicle::setModel(string mdl)
{
	model = mdl;
}
void Vehicle::setColor(string col)
{
	color = col;
}

//format
string Vehicle::toString()
{
	return vehicleID + "|" + customerID + "|" + make + "|" + model + "|" + year + "|" + regNo + "|" + color;
}

void Vehicle::fromString(string line)
{
	stringstream ss(line);
	string token;
	vector<string> f;
	while (getline(ss, token, '|'))
		f.push_back(token);
	if (f.size() == 7)
	{
		vehicleID = f[0];
		customerID = f[1];
		make = f[2];
		model = f[3];
		year = f[4];
		regNo = f[5];
		color = f[6];
	}
}

void Vehicle::displayInfo()
{
	cout << "-------------------------" << endl;
	cout << "Vehicle ID: " << vehicleID << endl;
	cout << "Owner ID: " << customerID << endl;
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Registration No. : " << regNo << endl;
	cout << "Color: " << color << endl;
	cout << "---------------------------" << endl;

}

