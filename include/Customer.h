#pragma once
#include<string>
#include<vector>
using namespace std;
class Customer
{
private:
	string customerID;
	string name;
	string address;
	string phone;
	string email;
	string registrationDate;

public:
	Customer();
	Customer(string id, string n, string addr, string ph, string em, string date);
	string getCustomerID();
	string getName();
	string getAddress();
	string getPhone();
	string getEmail();
	string getRegistrationDate();

	void setName(string n);
	void setAddress(string add);
	void setPhone(string ph);
	void setEmail(string em);

	string toString();

	void fromString(string line);

	void displayInfo();


};

