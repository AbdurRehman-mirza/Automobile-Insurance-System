#pragma once
#include<string>
using namespace std;
class Report
{
protected:
    string reportID;
    string generatedDate;
    string generatedBy;

public:
    Report();
    Report(string id, string date, string by);

    string getReportID();
    string getGeneratedDate();
    string getGeneratedBy();

    // Pure virtual — every subclass must implement
    virtual void generate() = 0;
    virtual void display() = 0;

    virtual ~Report();
};

