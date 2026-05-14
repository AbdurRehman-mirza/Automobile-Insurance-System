#pragma once
#include"Report.h"
#include"FileHandler.h"
#include"Claim.h"
#include<vector>
class PendingClaimsReport : public Report 
{

private:
    FileHandler& claimFile;
    vector<Claim> results;

public:
    PendingClaimsReport(string id, string date,
        string by, FileHandler& cf);

    void generate();
    void display();
};

