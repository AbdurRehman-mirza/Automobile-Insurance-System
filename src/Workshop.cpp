#include "Workshop.h"
#include<iostream>
#include<sstream>

Workshop::Workshop()
{
	workshopID = "";
	name = "";
	address = "";
	phone = "";
	status = "Registered";
}

Workshop::Workshop(string wid, string n, string addr, string ph, string stat)
{
	workshopID = wid;
	name = n;
	address = addr;
	phone = ph;
	status = stat;
}
string Workshop::getWorkshopID()
{
	return workshopID;
}
string Workshop::getName()
{
	return name;
}
string Workshop::getAddress()
{
	return address;
}
string Workshop::getPhone()
{
	return phone;
}
string Workshop::getStatus()
{
	return status;
}

void Workshop::setStatus(string stat)
{
	status = stat;
}
void Workshop::setPhone(string ph)
{
	phone = ph;
}

//format
string Workshop::toString()
{
	return workshopID + "|" + name + "|" + address + "|" + phone + "|" + status;
}

void Workshop::fromString(string line)
{
	stringstream ss(line);
	string token;
	vector<string> f;
	while (getline(ss, token, '|')) 
		f.push_back(token);
	if (f.size() == 5) 
	{
		workshopID = f[0]; 
		name = f[1];
		address = f[2]; 
		phone = f[3]; 
		status = f[4];
	}
}

void Workshop::displayInfo() {
	cout << "-----------------------------" << endl;
	cout << "Workshop ID : " << workshopID << endl;
	cout << "Name        : " << name << endl;
	cout << "Address     : " << address << endl;
	cout << "Phone       : " << phone << endl;
	cout << "Status      : " << status << endl;
	cout << "-----------------------------" << endl;
}
