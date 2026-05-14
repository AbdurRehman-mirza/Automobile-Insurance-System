#include "Staff.h"
#include<iostream>

Staff::Staff()
{
	staffID = "";
	name = "";
	phone = "";
	email = "";
	password = "";
}

Staff::Staff(string id, string n, string ph, string em, string pass)
{
	staffID = id;
	name = n;
	phone = ph;
	email = em;
	password = pass;
}

string Staff::getStaffID() 
{ 
	return staffID; 
}
string Staff::getName() 
{ 
	return name; 
}
string Staff::getPhone() 
{ 
	return phone; 
}
string Staff::getEmail() 
{ 
	return email; 
}
string Staff::getPassword() 
{ 
	return password; 
}

void Staff::setPhone(string ph) 
{ 
	phone = ph; 
}
void Staff::setEmail(string em) 
{ 
	email = em; 
}

void Staff::displayInfo() {
	cout << "Staff ID : " << staffID << endl;
	cout << "Name     : " << name << endl;
	cout << "Phone    : " << phone << endl;
	cout << "Email    : " << email << endl;
	cout << "Role     : " << getRole() << endl;
}

Staff::~Staff() {}
