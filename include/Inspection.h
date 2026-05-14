#pragma once
#ifndef INSPECTION_H
#define INSPECTION_H
#include<string>
#include<vector>
using namespace std;
class Inspection
{
private:
    string inspectionID;
    string claimID;
    string surveyorID;
    string date;
    string findings;
    string estimatedCost;
    string status;   // "Pending", "Submitted"

public:
    Inspection();
    Inspection(string iid, string cid, string sid, string dt, string find, string cost, string stat);

    string getInspectionID();
    string getClaimID();
    string getSurveyorID();
    string getDate();
    string getFindings();
    string getEstimatedCost();
    string getStatus();

    void setFindings(string find);
    void setEstimatedCost(string cost);
    void setStatus(string stat);

    string toString();
    void fromString(string line);
    void displayInfo();
};

#endif