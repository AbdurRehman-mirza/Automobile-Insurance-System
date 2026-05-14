#ifndef CLAIM_H
#define CLAIM_H

#include<string>
#include<vector>
using namespace std;
class Claim
{
private:
    string claimID;
    string policyID;
    string customerID;
    string vehicleID;
    string workshopID;
    string claimDate;
    string description;
    string claimAmount;
    string status;   // "Pending", "Approved", "Rejected"

public:
    Claim();
    Claim(string cid, string pid, string custID, string vid, string wid, string date, string desc, string amount, string stat);

    string getClaimID();
    string getPolicyID();
    string getCustomerID();
    string getVehicleID();
    string getWorkshopID();
    string getClaimDate();
    string getDescription();
    string getClaimAmount();
    string getStatus();

    void setStatus(string stat);
    void setWorkshopID(string wid);
    void setClaimAmount(string amount);

    string toString();
    void fromString(string line);
    void displayInfo();
};

#endif