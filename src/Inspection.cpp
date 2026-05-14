#include "Inspection.h"
#include<iostream>
#include<sstream>

Inspection::Inspection()
{
	inspectionID = "";
	claimID = "";
	surveyorID = "";
	date = "";
	findings = "";
	estimatedCost = "";
	status = "Pending";
}

Inspection::Inspection(string iid, string cid, string sid, string dt, string find, string cost, string stat)
{
	inspectionID = iid;
	claimID = cid;
	surveyorID = sid;
	date = dt;
	findings = find;
	estimatedCost = cost;
	status = stat;
}

string Inspection::getInspectionID() 
{ 
	return inspectionID; 
}
string Inspection::getClaimID() 
{ 
	return claimID; 
}
string Inspection::getSurveyorID() 
{ 
	return surveyorID; 
}
string Inspection::getDate() 
{ 
	return date; 
}
string Inspection::getFindings() 
{ 
	return findings; 
}
string Inspection::getEstimatedCost() 
{
	return estimatedCost; 
}
string Inspection::getStatus() 
{ 
	return status; 
}

void Inspection::setFindings(string find) 
{ 
	findings = find; 
}
void Inspection::setEstimatedCost(string cost) 
{ 
	estimatedCost = cost; 
}
void Inspection::setStatus(string stat) 
{ 
	status = stat; 
}

//format
string Inspection::toString() {
	return inspectionID + "|" + claimID + "|" + surveyorID + "|" + date + "|" + findings + "|" + estimatedCost + "|" + status;
}

void Inspection::fromString(string line) {
	stringstream ss(line);
	string token;
	vector<string> f;
	while (getline(ss, token, '|')) f.push_back(token);
	if (f.size() == 7) {
		inspectionID = f[0]; 
		claimID = f[1];
		surveyorID = f[2];
		date = f[3];
		findings = f[4]; 
		estimatedCost = f[5];
		status = f[6];
	}
}

void Inspection::displayInfo() {
	cout << "-----------------------------" << endl;
	cout << "Inspection ID  : " << inspectionID << endl;
	cout << "Claim ID       : " << claimID << endl;
	cout << "Surveyor ID    : " << surveyorID << endl;
	cout << "Date           : " << date << endl;
	cout << "Findings       : " << findings << endl;
	cout << "Estimated Cost : " << estimatedCost << endl;
	cout << "Status         : " << status << endl;
	cout << "-----------------------------" << endl;
}

