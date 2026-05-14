#pragma once
#include "Staff.h"
#include<vector>
class Salesman : public Staff
{
private:
	string salesRegion;
	string totalSales;

public:
	Salesman();
	Salesman(string id, string n, string ph, string em, string pass, string region);
	
	string getRole();
	string getSalesRegion();
	void setSalesRegion(string region);

	void displayInfo();
	string toString();
	void fromString(string line);

};

