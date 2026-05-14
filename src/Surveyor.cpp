#include "Surveyor.h"
#include <iostream>
#include <sstream>
using namespace std;

Surveyor::Surveyor() : Staff() {
    specialization = "";
    totalInspections = "0";
}

Surveyor::Surveyor(string id, string n, string ph, string em, string pass, string spec) : Staff(id, n, ph, em, pass) {
    specialization = spec;
    totalInspections = "0";
}

string Surveyor::getRole() 
{ 
    return "Surveyor"; 
}
string Surveyor::getSpecialization() 
{
    return specialization; 
}
void   Surveyor::setSpecialization(string spec) 
{ 
    specialization = spec; 
}

void Surveyor::displayInfo()
{
    cout << "-----------------------------" << endl;
    Staff::displayInfo();
    cout << "Specialization : " << specialization << endl;
    cout << "Inspections    : " << totalInspections << endl;
    cout << "-----------------------------" << endl;
}

//format
string Surveyor::toString()
{
    return staffID + "|" + name + "|" + phone + "|" + email + "|" + password + "|" + "Surveyor" + "|" + specialization + "|" + totalInspections;
}

void Surveyor::fromString(string line)
{
    stringstream ss(line);
    string token;
    vector<string> f;
    while (getline(ss, token, '|')) 
        f.push_back(token);
    if (f.size() == 8) 
    {
        staffID = f[0]; 
        name = f[1];
        phone = f[2]; 
        email = f[3];
        password = f[4]; // f[5] = role
        specialization = f[6]; 
        totalInspections = f[7];
    }
}