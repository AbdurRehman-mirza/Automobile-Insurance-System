#include<string>
#include<vector>
using namespace std;

class Vehicle
{
private:
	string vehicleID;
	string customerID;
	string make;
	string model;
	string year;
	string regNo;
	string color;

public:
	Vehicle();
	Vehicle(string vid, string cid, string mk, string mdl, string yr, string reg, string col);

	string getVehicleID();
	string getCustomerID();
	string getMake();
	string getModel();
	string getYear();
	string getRegNo();
	string getColor();

	void setMake(string mk);
	void setModel(string mdl);
	void setColor(string col);

	string toString();
	void fromString(string line);
	void displayInfo();
};

