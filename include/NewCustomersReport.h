#pragma once
#include"FileHandler.h"
#include"Customer.h"
#include"Report.h"
#include<vector>

class NewCustomersReport : public Report 
{
private:
	string month;
	string year;
	FileHandler& customerFile;
	vector<Customer> results;

public:
	NewCustomersReport(string id, string date, string by, string m, string y, FileHandler& cf);

	void generate();
	void display();

};

