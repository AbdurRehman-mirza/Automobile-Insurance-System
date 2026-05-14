#include "Manager.h"
#include<iostream>
#include<sstream>

Manager::Manager()
{
	managerID = "";
	name = "";
	phone = "";
	email = "";
	password = "";
}

Manager::Manager(string id, string n, string ph, string em, string pass)
{
	managerID = id;
	name = n;
	phone = ph;
	email = em;
	password = pass;
}

string Manager::getManagerID() 
{
	return managerID; 
}
string Manager::getName() 
{ 
	return name; 
}
string Manager::getPassword() 
{ 
	return password; 
}

void Manager::approveClaim(string claimID, FileHandler& claimFile) {
    string line = claimFile.getLineByID(claimID);
    if (line.empty()) 
    {
        cout << "Claim not found: " << claimID << endl;
        return;
    }

    Claim c;
    c.fromString(line);

    if (c.getStatus() != "Pending") 
    {
        cout << "Claim is already " << c.getStatus() << endl;
        return;
    }

    c.setStatus("Approved");
    claimFile.deleteByID(claimID);
    claimFile.appendLine(c.toString());
    cout << "Claim " << claimID << " approved successfully." << endl;
}

// Reject a claim — sets status to "Rejected"
// ─────────────────────────────────────────────────────────────
void Manager::rejectClaim(string claimID, FileHandler& claimFile) {
    string line = claimFile.getLineByID(claimID);
    if (line.empty()) 
    {
        cout << "Claim not found: " << claimID << endl;
        return;
    }

    Claim c;
    c.fromString(line);

    if (c.getStatus() != "Pending") 
    {
        cout << "Claim is already " << c.getStatus() << endl;
        return;
    }

    c.setStatus("Rejected");
    claimFile.deleteByID(claimID);
    claimFile.appendLine(c.toString());
    cout << "Claim " << claimID << " rejected." << endl;
}
// View all pending claims
// ─────────────────────────────────────────────────────────────
void Manager::viewPendingClaims(FileHandler& claimFile) {
    vector<string> lines = claimFile.readAllLines();
    int count = 0;

    cout << "\n===== PENDING CLAIMS =====" << endl;
    for (int i = 0; i < (int)lines.size(); i++) {
        Claim c;
        c.fromString(lines[i]);
        if (c.getStatus() == "Pending") {
            c.displayInfo();
            count++;
        }
    }

    if (count == 0) {
        cout << "No pending claims found." << endl;
    }
    cout << "Total pending: " << count << endl;
}

// View all claims for a specific customer
// ─────────────────────────────────────────────────────────────
void Manager::viewCustomerClaims(string customerID,
    FileHandler& claimFile) {
    vector<string> lines = claimFile.readAllLines();
    int count = 0;

    cout << "\n===== CLAIMS FOR CUSTOMER: "
        << customerID << " =====" << endl;

    for (int i = 0; i < (int)lines.size(); i++) {
        Claim c;
        c.fromString(lines[i]);
        if (c.getCustomerID() == customerID) {
            c.displayInfo();
            count++;
        }
    }

    if (count == 0) {
        cout << "No claims found for customer: "
            << customerID << endl;
    }
}

// View inspection report for a given claim
// ─────────────────────────────────────────────────────────────
void Manager::viewInspectionReport(string claimID, FileHandler& inspFile) {
    vector<string> lines = inspFile.readAllLines();
    bool found = false;

    cout << "\n===== INSPECTION REPORT FOR CLAIM: "
        << claimID << " =====" << endl;

    for (int i = 0; i < (int)lines.size(); i++) {
        Inspection ins;
        ins.fromString(lines[i]);
        if (ins.getClaimID() == claimID) {
            ins.displayInfo();
            found = true;
        }
    }

    if (!found) {
        cout << "No inspection found for claim: "
            << claimID << endl;
    }
}

// Display / toString / fromString
// ─────────────────────────────────────────────────────────────
void Manager::displayInfo() {
    cout << "-----------------------------" << endl;
    cout << "Manager ID : " << managerID << endl;
    cout << "Name       : " << name << endl;
    cout << "Phone      : " << phone << endl;
    cout << "Email      : " << email << endl;
    cout << "-----------------------------" << endl;
}

// Format: managerID|name|phone|email|password
string Manager::toString() {
    return managerID + "|" + name + "|" +
        phone + "|" + email + "|" + password;
}

void Manager::fromString(string line) {
    stringstream ss(line);
    string token;
    vector<string> f;
    while (getline(ss, token, '|')) 
        f.push_back(token);
    if (f.size() == 5) 
    {
        managerID = f[0]; 
        name = f[1];
        phone = f[2]; 
        email = f[3];
        password = f[4];
    }
}

