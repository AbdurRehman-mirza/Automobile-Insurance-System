#pragma once
#include<string>
using namespace std;
class Staff
{
protected:
	string staffID;
	string name;
	string phone;
	string email;
	string password;

public:
	Staff();
	Staff(string id, string n, string ph, string em, string pass);

    string getStaffID();
    string getName();
    string getPhone();
    string getEmail();
    string getPassword();

    void setPhone(string ph);
    void setEmail(string em);

    // Pure virtual — makes Staff abstract
    // Every subclass MUST implement this
    virtual string getRole() = 0;
    virtual void displayInfo();
    virtual string toString() = 0;
    virtual void fromString(string ln) = 0;

    virtual ~Staff();
};

