#include "Report.h"
#include<iostream>

Report::Report()
{
	reportID = "";
	generatedDate = "";
	generatedBy = "";
}
Report::Report(string id, string date, string by)
{
	reportID = id;
	generatedDate = date;
	generatedBy = by;
}

string Report::getReportID()
{
	return reportID;
}
string Report::getGeneratedDate()
{
	return generatedDate;
}
string Report::getGeneratedBy()
{
	return generatedBy;
}

Report::~Report() {}
