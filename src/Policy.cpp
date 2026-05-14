#include "Policy.h"
#include<iostream>
#include<sstream>

Policy::Policy()
{
	policyID = "";
	customerID = "";
	vehicleID = "";
	startDate = "";
	endDate = "";
	policyType = "";
	premiumAmount = "";
	status = "";
}

Policy::Policy(string pid, string cid, string vid, string start, string end, string type, string premium, string stat)
{
	policyID = pid;
	customerID = cid;
	vehicleID = vid;
	startDate = start;
	endDate = end;
	policyType = type;
	premiumAmount = premium;
	status = stat;
}

string Policy::getPolicyID()
{
	return policyID;
}
string Policy::getCustomerID()
{
	return customerID;
}
string Policy::getVehicleID()
{
	return vehicleID;
}
string Policy::getStartDate()
{
	return startDate;
}
string Policy::getEndDate()
{
	return endDate;
}
string Policy::getPolicyType()
{
	return policyType;
}
string Policy::getPremiumAmount()
{
	return premiumAmount;
}
string Policy::getStatus()
{
	return status;
}

void Policy::setStatus(string stat)
{
	status = stat;
}
void Policy::setPremiumAmount(string amount)
{
	premiumAmount = amount;
}

bool Policy::isActive()
{
	return status == "Active";
}

//format
string Policy::toString()
{
	return policyID + "|" + customerID + "|" + vehicleID + "|" + startDate + "|" + endDate + "|" + policyType + "|" + premiumAmount + "|" + status;
}

void Policy::fromString(string line)
{
	stringstream ss(line);
	string token;
	vector<string> f;
	while (getline(ss, token, '|'))
		f.push_back(token);
	if (f.size() == 8)
	{
		policyID = f[0];
		customerID = f[1];
		vehicleID = f[2];
		startDate = f[3];
		endDate = f[4];
		policyType = f[5];
		premiumAmount = f[6];
		status = f[7];

	}
		
}

void Policy::displayInfo()
{
	cout << "------------------------" << endl;
	cout << "Policy ID: " << policyID << endl;
	cout << "Customer ID: " << customerID << endl;
	cout << "Vehicle ID: " << vehicleID << endl;
	cout << "Type: " << policyType << endl;
	cout << "Start Date: " << startDate << endl;
	cout << "End Date: " << endDate << endl;
	cout << "Premium: " << premiumAmount << endl;
	cout << "Status: " << status << endl;
	cout << "-----------------------------" << endl;
}
