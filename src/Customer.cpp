#include "Customer.h"
#include<iostream>
#include<sstream>
#include "Vehicle.h"

Customer::Customer()
{
	customerID = "";
	name = "";
	address = "";
	phone = "";
	email = "";
	registrationDate = "";
}

Customer::Customer(string id, string n, string addr, string ph, string em, string date)
{
	customerID = id;
	name = n;
	address = addr;
	phone = ph;
	email = em;
	registrationDate = date;
}



string Customer::getCustomerID()
{
	return customerID;
}
string Customer::getName()
{
	return name;
}
string Customer::getAddress()
{
	return address;
}
string Customer::getPhone()
{
	return phone;
}

string Customer::getEmail()
{
	return email;
}

string Customer::getRegistrationDate()
{
	return string();
}

void Customer::setName(string n)
{
	name = n;
}

void Customer::setAddress(string add)
{
	address = add;
}

void Customer::setPhone(string ph)
{
	phone = ph;
}

void Customer::setEmail(string em)
{
	email = em;
}

//printing format
string Customer::toString()
{
	return customerID + "|" + name + "|" + address + "|" + phone + "|" + email + "|" + registrationDate;

}

void Customer::fromString(string line)
{
	stringstream ss(line);
	string token;
	vector<string> fields;

	while(getline(ss, token, '|'))
	{
		fields.push_back(token);
	}

	if (fields.size() == 6)
	{
		customerID = fields[0];
		name = fields[1];
		address = fields[2];
		phone = fields[3];
		email = fields[4];
		registrationDate = fields[5];
	}
}

void Customer::displayInfo()
{
	cout << "-----------------------------" << endl;
	cout << "Customer ID: " << customerID << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Phone: " << phone << endl;
	cout << "Email: " << email << endl;
	cout << "Registered On: " << registrationDate << endl;
	cout << "------------------------------" << endl;
}




