#pragma once
#include"Staff.h"
#include<vector>
class Surveyor : public Staff
{
private:
	string specialization;
	string totalInspections;

public:
	Surveyor();
	Surveyor(string id, string n, string ph, string em, string pass, string spec);

	string getRole();
	string getSpecialization();
	void setSpecialization(string spec);

	void displayInfo();
	string toString();
	void fromString(string line);
};

