#pragma once
#include<string>
#include<vector>
#include"FileHandler.h"
#include"Claim.h"
#include"Inspection.h"
using namespace std;

class Manager
{
private:
    string managerID;
    string name;
    string phone;
    string email;
    string password;

public:
    Manager();
    Manager(string id, string n, string ph,
        string em, string pass);

    string getManagerID();
    string getName();
    string getPassword();

    // Core manager operations
    void approveClaim(string claimID, FileHandler& claimFile);
    void rejectClaim(string claimID, FileHandler& claimFile);

    // View all pending claims
    void viewPendingClaims(FileHandler& claimFile);

    // View all previous claims for a customer
    void viewCustomerClaims(string customerID,
        FileHandler& claimFile);

    // View inspection report for a claim
    void viewInspectionReport(string claimID,
        FileHandler& inspFile);

    void displayInfo();
    string toString();
    void fromString(string line);
};

