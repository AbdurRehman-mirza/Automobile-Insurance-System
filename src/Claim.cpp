#include "Claim.h"
#include<iostream>
#include<sstream>

Claim::Claim()
{
	claimID = "";
	policyID = ""; 
	customerID = "";
	vehicleID = ""; 
	workshopID = ""; 
	claimDate = "";
	description = ""; 
	claimAmount = ""; 
	status = "Pending";
}

Claim::Claim(string cid, string pid, string custID, string vid, string wid, string date, string desc, string amount, string stat)
{
	claimID = cid;
	policyID = pid;
	customerID = custID;
	vehicleID = vid;
	workshopID = wid;
	claimDate = date;
	description = desc;
	claimAmount = amount;
	status = stat;
}
string Claim::getClaimID()
{
	return claimID;
}

string Claim::getPolicyID() 
{ 
	return policyID; 
}
string Claim::getCustomerID() 
{ 
	return customerID; 
}
string Claim::getVehicleID() 
{ 
	return vehicleID; 
}
string Claim::getWorkshopID() 
{ 
	return workshopID; 
}
string Claim::getClaimDate() 
{ 
	return claimDate; 
}
string Claim::getDescription() 
{ 
	return description; 
}
string Claim::getClaimAmount() 
{ 
	return claimAmount; 
}
string Claim::getStatus() 
{ 
	return status; 
}

void Claim::setStatus(string stat)
{
	status = stat;
}
void Claim::setWorkshopID(string wid)
{
	workshopID = wid;
}
void Claim::setClaimAmount(string amount)
{
	claimAmount = amount;
}

string Claim::toString()
{
	return claimID + "|" + policyID + "|" + customerID + "|" + vehicleID + "|" + workshopID + "|" + claimDate + "|" + description + "|" + claimAmount + "|" + status;
}
void Claim::fromString(string line) {
	stringstream ss(line);
	string token;
	vector<string> f;
	while (getline(ss, token, '|')) f.push_back(token);
	if (f.size() == 9) {
		claimID = f[0]; 
		policyID = f[1];
		customerID = f[2]; 
		vehicleID = f[3];
		workshopID = f[4]; 
		claimDate = f[5];
		description = f[6]; 
		claimAmount = f[7];
		status = f[8];
	}
}

void Claim::displayInfo() {
	cout << "-----------------------------" << endl;
	cout << "Claim ID     : " << claimID << endl;
	cout << "Policy ID    : " << policyID << endl;
	cout << "Customer ID  : " << customerID << endl;
	cout << "Vehicle ID   : " << vehicleID << endl;
	cout << "Workshop ID  : " << workshopID << endl;
	cout << "Date         : " << claimDate << endl;
	cout << "Description  : " << description << endl;
	cout << "Amount       : " << claimAmount << endl;
	cout << "Status       : " << status << endl;
	cout << "-----------------------------" << endl;
}