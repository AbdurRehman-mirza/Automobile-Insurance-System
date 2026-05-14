#include "Salesman.h"
#include<iostream>
#include<sstream>
using namespace std;

Salesman::Salesman() : Staff() 
{
    salesRegion = ""; totalSales = "0";
}

Salesman::Salesman(string id, string n, string ph, string em, string pass, string region) : Staff(id, n, ph, em, pass) {
    salesRegion = region;
    totalSales = "0";
}

string Salesman::getRole() 
{ 
    return "Salesman"; 
}
string Salesman::getSalesRegion() 
{ 
    return salesRegion; 
}
void   Salesman::setSalesRegion(string region) 
{ 
    salesRegion = region; 
}

void Salesman::displayInfo() 
{
    cout << "-----------------------------" << endl;
    Staff::displayInfo();
    cout << "Region   : " << salesRegion << endl;
    cout << "Sales    : " << totalSales << endl;
    cout << "-----------------------------" << endl;
}

string Salesman::toString() {
    return staffID + "|" + name + "|" + phone + "|" + email + "|" + password + "|" + "Salesman" + "|" + salesRegion + "|" + totalSales;
}

void Salesman::fromString(string line) 
{
    stringstream ss(line);
    string token;
    vector<string> f;

    while (getline(ss, token, '|')) 
        f.push_back(token);

    if (f.size() == 8) 
    {
        staffID = f[0]; name = f[1];
        phone = f[2]; email = f[3];
        password = f[4]; // f[5] = role
        salesRegion = f[6]; totalSales = f[7];
    }
}
