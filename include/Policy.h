#include<string>
#include<vector>
using namespace std;
class Policy
{
private:
    string policyID;
    string customerID;
    string vehicleID;
    string startDate;
    string endDate;
    string policyType;    // e.g. "Comprehensive", "Third-Party"
    string premiumAmount;
    string status;        // "Active" or "expired"

public:
    Policy();
    Policy(string pid, string cid, string vid, string start, string end, string type, string premium, string stat);

    string getPolicyID();
    string getCustomerID();
    string getVehicleID();
    string getStartDate();
    string getEndDate();
    string getPolicyType();
    string getPremiumAmount();
    string getStatus();

    void setStatus(string stat);
    void setPremiumAmount(string amt);

    bool isActive();

    string toString();
    void fromString(string line);
    void displayInfo();
};

