#include<string>
#include<vector>
using namespace std;
class Workshop
{
private:
    string workshopID;
    string name;
    string address;
    string phone;
    string status;   // "Registered" or "Suspended"

public:
    Workshop();
    Workshop(string wid, string n, string addr, string ph, string stat);

    string getWorkshopID();
    string getName();
    string getAddress();
    string getPhone();
    string getStatus();

    void setStatus(string stat);
    void setPhone(string ph);

    string toString();
    void fromString(string line);
    void displayInfo();
};

