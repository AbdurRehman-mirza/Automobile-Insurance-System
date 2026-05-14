#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include "FileHandler.h"
#include "Customer.h"
#include "Vehicle.h"
#include "Policy.h"
#include "Claim.h"
#include "Inspection.h"
#include "Workshop.h"
#include "Salesman.h"
#include "Surveyor.h"
#include "Manager.h"
#include "NewCustomersReport.h"
#include "PendingClaimsReport.h"
#include "InspectionReport.h"
using namespace std;

// File paths  (relative to working directory = project folder)
const string F_CUSTOMERS = "data/customers.txt";
const string F_VEHICLES = "data/vehicles.txt";
const string F_POLICIES = "data/policies.txt";
const string F_CLAIMS = "data/claims.txt";
const string F_INSPECTIONS = "data/inspections.txt";
const string F_WORKSHOPS = "data/workshops.txt";
const string F_STAFF = "data/staff.txt";
const string F_MANAGERS = "data/managers.txt";

// Utility: get today's date as DD-MM-YYYY  (VS safe version)
string getToday() {
    time_t now = time(0);
    struct tm t;
    localtime_s(&t, &now);
    char buf[20];
    sprintf_s(buf, sizeof(buf), "%02d-%02d-%04d",
        t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
    return string(buf);
}

// Utility: generate simple ID  e.g. "C001"
string generateID(string prefix, FileHandler& fh) {
    vector<string> lines = fh.readAllLines();
    int next = (int)lines.size() + 1;
    char buf[20];
    sprintf_s(buf, sizeof(buf), "%03d", next);
    return prefix + string(buf);
}

void separator() {
    cout << "\n========================================\n";
}

// SALESMAN MENU
void salesmanMenu(Salesman& s) {
    FileHandler custFH(F_CUSTOMERS);
    FileHandler vehFH(F_VEHICLES);
    FileHandler polFH(F_POLICIES);
    FileHandler wsFH(F_WORKSHOPS);
    int choice;

    while(1) {
        separator();
        cout << "  SALESMAN MENU  — " << s.getName() << endl;
        separator();
        cout << "1. Register New Customer" << endl;
        cout << "2. Add Vehicle for Customer" << endl;
        cout << "3. Sell Policy" << endl;
        cout << "4. View All Customers" << endl;
        cout << "5. View All Policies" << endl;
        cout << "6. View All Workshops" << endl;
        cout << "0. Logout"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name, addr, phone, email;
            string id = generateID("C", custFH);
            cout << "Name    : "; 
            getline(cin, name);
            cout << "Address : "; 
            getline(cin, addr);
            cout << "Phone   : "; 
            getline(cin, phone);
            cout << "Email   : "; 
            getline(cin, email);
            Customer nc(id, name, addr, phone, email, getToday());
            custFH.appendLine(nc.toString());
            cout << "Customer registered! ID = " << id << endl;

        }
        else if (choice == 2) {
            string cid, make, model, year, reg, color;
            cout << "Customer ID : "; 
            getline(cin, cid);
            if (!custFH.exists(cid)) {
                cout << "Customer not found." << endl; 
                continue;
            }
            string vid = generateID("V", vehFH);
            cout << "Make        : "; 
            getline(cin, make);
            cout << "Model       : "; 
            getline(cin, model);
            cout << "Year        : "; 
            getline(cin, year);
            cout << "Reg No      : "; 
            getline(cin, reg);
            cout << "Color       : "; 
            getline(cin, color);
            Vehicle v(vid, cid, make, model, year, reg, color);
            vehFH.appendLine(v.toString());
            cout << "Vehicle added! ID = " << vid << endl;

        }
        else if (choice == 3) {
            string cid, vid, type, premium, start, end;
            cout << "Customer ID    : "; 
            getline(cin, cid);
            if (!custFH.exists(cid)) {
                cout << "Customer not found." << endl; 
                continue;
            }
            cout << "Vehicle ID     : "; 
            getline(cin, vid);
            if (!vehFH.exists(vid)) {
                cout << "Vehicle not found." << endl; 
                continue;
            }
            cout << "Policy Type    : "; 
            getline(cin, type);
            cout << "Premium Amount : "; 
            getline(cin, premium);
            cout << "Start Date     : "; 
            getline(cin, start);
            cout << "End Date       : "; 
            getline(cin, end);
            string pid = generateID("P", polFH);
            Policy p(pid, cid, vid, start, end, type, premium, "Active");
            polFH.appendLine(p.toString());
            cout << "Policy sold! ID = " << pid << endl;

        }
        else if (choice == 4) {
            vector<string> lines = custFH.readAllLines();
            separator();
            cout << "  ALL CUSTOMERS"; 
            separator();
            if (lines.empty()) cout << "No customers found." << endl;
            for (int i = 0; i < (int)lines.size(); i++) {
                Customer c; c.fromString(lines[i]); 
                c.displayInfo();
            }

        }
        else if (choice == 5) {
            vector<string> lines = polFH.readAllLines();
            separator();
            cout << "  ALL POLICIES"; 
            separator();
            for (int i = 0; i < (int)lines.size(); i++) {
                Policy p; p.fromString(lines[i]); 
                p.displayInfo();
            }

        }
        else if (choice == 6) {
            vector<string> lines = wsFH.readAllLines();
            separator();
            cout << "  REGISTERED WORKSHOPS"; separator();
            for (int i = 0; i < (int)lines.size(); i++) {
                Workshop w; w.fromString(lines[i]); w.displayInfo();
            }
        }
        else if (choice == 0)
        {
            break;
        }

    } 
}

// SURVEYOR MENU
void surveyorMenu(Surveyor& sv) {
    FileHandler claimFH(F_CLAIMS);
    FileHandler inspFH(F_INSPECTIONS);
    int choice;

    while(1) {
        separator();
        cout << "  SURVEYOR MENU  — " << sv.getName() << endl;
        separator();
        cout << "1. View Pending Claims" << endl;
        cout << "2. Submit Inspection Report" << endl;
        cout << "3. View My Submitted Inspections" << endl;
        cout << "0. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            vector<string> claims = claimFH.readAllLines();
            separator();
            cout << "  PENDING CLAIMS"; separator();
            bool any = false;
            for (int i = 0; i < (int)claims.size(); i++) {
                Claim c; c.fromString(claims[i]);
                if (c.getStatus() == "Pending") {
                    c.displayInfo(); 
                    any = true;
                }
            }
            if (!any) cout << "No pending claims." << endl;

        }
        else if (choice == 2) {
            string claimID, findings, cost, date;
            cout << "Claim ID       : "; getline(cin, claimID);
            if (!claimFH.exists(claimID)) {
                cout << "Claim not found." << endl; 
                continue;
            }
            cout << "Date           : "; getline(cin, date);
            cout << "Findings       : "; getline(cin, findings);
            cout << "Estimated Cost : "; getline(cin, cost);
            string iid = generateID("I", inspFH);
            Inspection ins(iid, claimID, sv.getStaffID(),
                date, findings, cost, "Submitted");
            inspFH.appendLine(ins.toString());
            cout << "Inspection submitted! ID = " << iid << endl;

        }
        else if (choice == 3) {
            vector<string> lines = inspFH.readAllLines();
            separator();
            cout << "  MY INSPECTIONS"; 
            separator();
            bool any = false;
            for (int i = 0; i < (int)lines.size(); i++) {
                Inspection ins; ins.fromString(lines[i]);
                if (ins.getSurveyorID() == sv.getStaffID()) {
                    ins.displayInfo(); any = true;
                }
            }
            if (!any) cout << "No inspections found." << endl;
        }
        else if (choice == 0)
        {
            break;
        }

    } 
}

// MANAGER MENU
void managerMenu(Manager& mgr) {
    FileHandler claimFH(F_CLAIMS);
    FileHandler inspFH(F_INSPECTIONS);
    FileHandler custFH(F_CUSTOMERS);
    FileHandler wsFH(F_WORKSHOPS);
    int choice;

    while(1) {
        separator();
        cout << "  MANAGER MENU  — " << mgr.getName() << endl;
        separator();
        cout << "1.  Approve a Claim" << endl;
        cout << "2.  Reject a Claim" << endl;
        cout << "3.  View Pending Claims" << endl;
        cout << "4.  View Inspection Report for a Claim" << endl;
        cout << "5.  View All Claims of a Customer" << endl;
        cout << "6.  Generate New Customers Report" << endl;
        cout << "7.  Generate Pending Claims Report" << endl;
        cout << "8.  Generate All Inspections Report" << endl;
        cout << "9.  Add Registered Workshop" << endl;
        cout << "10. View All Workshops" << endl;
        cout << "0.  Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string cid;
            cout << "Enter Claim ID to approve: "; 
            getline(cin, cid);
            mgr.approveClaim(cid, claimFH);

        }
        else if (choice == 2) {
            string cid;
            cout << "Enter Claim ID to reject: "; 
            getline(cin, cid);
            mgr.rejectClaim(cid, claimFH);

        }
        else if (choice == 3) {
            mgr.viewPendingClaims(claimFH);

        }
        else if (choice == 4) {
            string cid;
            cout << "Enter Claim ID: ";
            getline(cin, cid);
            mgr.viewInspectionReport(cid, inspFH);

        }
        else if (choice == 5) {
            string custID;
            cout << "Enter Customer ID: ";
            getline(cin, custID);
            mgr.viewCustomerClaims(custID, claimFH);

        }
        else if (choice == 6) {
            string month, year;
            cout << "Month (MM)   : ";
            getline(cin, month);
            cout << "Year  (YYYY) : "; 
            getline(cin, year);
            NewCustomersReport r("RPT001", getToday(),
                mgr.getName(), month, year, custFH);
            r.generate();
            r.display();

        }
        else if (choice == 7) {
            PendingClaimsReport r("RPT002", getToday(),
                mgr.getName(), claimFH);
            r.generate();
            r.display();

        }
        else if (choice == 8) {
            InspectionReport r("RPT003", getToday(),
                mgr.getName(), inspFH);
            r.generate();
            r.display();

        }
        else if (choice == 9) {
            string name, addr, phone;
            string wid = generateID("W", wsFH);
            cout << "Workshop Name : "; 
            getline(cin, name);
            cout << "Address       : "; 
            getline(cin, addr);
            cout << "Phone         : "; 
            getline(cin, phone);
            Workshop w(wid, name, addr, phone, "Registered");
            wsFH.appendLine(w.toString());
            cout << "Workshop added! ID = " << wid << endl;

        }
        else if (choice == 10) {
            vector<string> lines = wsFH.readAllLines();
            separator();
            cout << "  ALL WORKSHOPS"; 
            separator();
            for (int i = 0; i < (int)lines.size(); i++) {
                Workshop w; w.fromString(lines[i]); 
                w.displayInfo();
            }
        }
        else if (choice == 0)
        {
            break;
        }

    } 
}

// CUSTOMER MENU
void customerMenu(Customer& cust) {
    FileHandler polFH(F_POLICIES);
    FileHandler claimFH(F_CLAIMS);
    FileHandler inspFH(F_INSPECTIONS);
    FileHandler wsFH(F_WORKSHOPS);
    int choice;

    while(1) {
        separator();
        cout << "  CUSTOMER MENU  — " << cust.getName() << endl;
        separator();
        cout << "1. View My Policies\n";
        cout << "2. File a New Claim\n";
        cout << "3. View My Claims\n";
        cout << "4. View Inspection Report\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            vector<string> lines = polFH.readAllLines();
            separator();
            cout << "  MY POLICIES"; separator();
            bool any = false;
            for (int i = 0; i < (int)lines.size(); i++) {
                Policy p; p.fromString(lines[i]);
                if (p.getCustomerID() == cust.getCustomerID()) {
                    p.displayInfo(); any = true;
                }
            }
            if (!any) cout << "No policies found." << endl;

        }
        else if (choice == 2) {
            string pid, vid, wid, desc, amt;
            cout << "Policy ID   : "; 
            getline(cin, pid);
            if (!polFH.exists(pid)) {
                cout << "Policy not found." << endl; 
                continue;
            }
            cout << "Vehicle ID  : "; 
            getline(cin, vid);
            cout << "Workshop ID : "; 
            getline(cin, wid);
            if (!wsFH.exists(wid)) {
                cout << "Workshop not registered." << endl; 
                continue;
            }
            cout << "Description : "; 
            getline(cin, desc);
            cout << "Claim Amount: "; 
            getline(cin, amt);
            string cid = generateID("CL", claimFH);
            Claim cl(cid, pid, cust.getCustomerID(),
                vid, wid, getToday(), desc, amt, "Pending");
            claimFH.appendLine(cl.toString());
            cout << "Claim filed! ID = " << cid << endl;

        }
        else if (choice == 3) {
            vector<string> lines = claimFH.readAllLines();
            separator();
            cout << "  MY CLAIMS"; separator();
            bool any = false;
            for (int i = 0; i < (int)lines.size(); i++) {
                Claim c; 
                c.fromString(lines[i]);
                if (c.getCustomerID() == cust.getCustomerID()) {
                    c.displayInfo(); any = true;
                }
            }
            if (!any) cout << "No claims found." << endl;

        }
        else if (choice == 4) {
            string claimID;
            cout << "Enter Claim ID: "; getline(cin, claimID);
            vector<string> lines = inspFH.readAllLines();
            bool any = false;
            for (int i = 0; i < (int)lines.size(); i++) {
                Inspection ins; ins.fromString(lines[i]);
                if (ins.getClaimID() == claimID) {
                    ins.displayInfo(); any = true;
                }
            }
            if (!any) cout << "No inspection found." << endl;
        }
        else if (choice == 0)
        {
            break;
        }

    }
}

// LOGIN
void loginMenu() {
    FileHandler staffFH(F_STAFF);
    FileHandler mgrFH(F_MANAGERS);
    FileHandler custFH(F_CUSTOMERS);
    int choice;

    while(1) 
    {
        separator();
        cout << "  AUTOMOBILE INSURANCE SYSTEM" << endl;
        separator();
        cout << "Login as:" << endl;
        cout << "1. Salesman" << endl;
        cout << "2. Surveyor" << endl;
        cout << "3. Manager" << endl;
        cout << "4. Customer" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 || choice == 2) {
            string id, pass;
            cout << "Staff ID  : "; 
            cin >> id;
            cout << "Password  : "; 
            cin >> pass;

            string line = staffFH.getLineByID(id);
            if (line.empty()) {
                cout << "Staff not found." << endl; 
                continue;
            }

            vector<string> f;
            string tok;
            stringstream ss(line);
            while (getline(ss, tok, '|')) 
                f.push_back(tok);

            if (f.size() < 6) {
                cout << "Invalid record." << endl; 
                continue;
            }
            if (f[4] != pass) {
                cout << "Wrong password." << endl; 
                continue;
            }

            if (f[5] == "Salesman" && choice == 1) {
                Salesman s; 
                s.fromString(line);
                cout << "Welcome, " << s.getName() << "!" << endl;
                salesmanMenu(s);
            }
            else if (f[5] == "Surveyor" && choice == 2) {
                Surveyor sv; 
                sv.fromString(line);
                cout << "Welcome, " << sv.getName() << "!" << endl;
                surveyorMenu(sv);
            }
            else {
                cout << "Role mismatch. Try again." << endl;
            }

        }
        else if (choice == 3) 
        {
            string id, pass;
            cout << "Manager ID : "; 
            cin >> id;
            cout << "Password   : "; 
            cin >> pass;

            string line = mgrFH.getLineByID(id);
            if (line.empty()) {
                cout << "Manager not found." << endl; 
                continue;
            }
            Manager mgr; mgr.fromString(line);
            if (mgr.getPassword() != pass) {
                cout << "Wrong password." << endl; 
                continue;
            }
            cout << "Welcome, " << mgr.getName() << "!" << endl;
            managerMenu(mgr);

        }
        else if (choice == 4) 
        {
            string id;
            cout << "Customer ID : "; 
            getline(cin, id);
            string line = custFH.getLineByID(id);
            if (line.empty()) {
                cout << "Customer not found." << endl; 
                continue;
            }
            Customer cust; cust.fromString(line);
            cout << "Welcome, " << cust.getName() << "!" << endl;
            customerMenu(cust);
        }
        else if (choice == 0)
        {
            cout << "\nGoodbye!" << endl;
            return;
        }

    } 

    
}

// MAIN
int main() {
    // Seed default manager account on first run
    FileHandler mgrFH(F_MANAGERS);
    if (!mgrFH.exists("MGR001")) {
        Manager defaultMgr("MGR001", "Admin Manager",
            "0300-0000000",
            "admin@insurance.com", "admin123");
        mgrFH.appendLine(defaultMgr.toString());
        cout << "Default manager created: MGR001 / admin123" << endl;
    }

    loginMenu();
    return 0;
}
