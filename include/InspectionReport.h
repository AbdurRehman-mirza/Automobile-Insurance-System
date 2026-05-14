#pragma once
#include "Report.h"
#include "FileHandler.h"
#include "Inspection.h"
#include <vector>
class InspectionReport : public Report
{
private:
    FileHandler& inspFile;
    vector<Inspection> results;

public:
    InspectionReport(string id, string date,
        string by, FileHandler& inf);

    void generate();
    void display();
};

