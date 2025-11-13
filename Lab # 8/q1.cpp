#include <iostream>
#include <iomanip> // setw(), setfll(char a) is header fill mein mujood hein.
#include <sstream>
#include <vector>
using namespace std;
class Electronics{
    public:
    string deviceType;
    double powerRating;
    bool status;
   
    Electronics(){
        deviceType = "general" ;
        powerRating = 64.55;
        status = false ;
       
    }
    Electronics(string t, double r, bool s) : deviceType(t) , powerRating(r), status(s) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual double calculatePowerUsage(int hours) = 0; // pure virtual (abstract)
    virtual void display() const = 0; 
};
class LED : public Electronics {
private:
    static int count;      // LED ka counter hai Jisse se agai LED ki ID banne gi.
    string id;             // aur har LED ke objects ki uniques ID hai.

public:
     double power;
     LED(double rating, bool s) : Electronics("LED", rating, s) {
        // Ye unique IDs banai ga is tarah se L001, L002, L003 and etc.
        stringstream ss;
        ss << "L" << setw(3) << setfill('0') << ++count;
        id = ss.str();
    }
    void turnOn() override {
        status = true;
        cout << "The device turned on!" << endl;
    }
    void turnOff() override {
        status = false;
        cout << "The device turned off!" << endl;
    }
    void Status() const {
    if (status)
        cout << "The device is ON" << endl;
    else
        cout << "The device is OFF" << endl;
}

    double calculatePowerUsage(int hours) override {
        power = powerRating * hours;
        return power;
    }
    void display() const override {
        cout << "Device Type: " << deviceType << endl;
        cout << "Device ID: " << id << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};
int LED::count = 0;

class Fan : public Electronics{
private:
     static int count;      // Fan ka counter hai 
    string id;             // aur har Fan object ki unique ID hai.
public:
    double power;
    int speedFactor;
     Fan(double rating, bool s, int sf) : Electronics("Fan", rating, s) , speedFactor(sf) {
        // Ye unique IDs banai ga is tarah se F001, F002, F003 and etc.
        stringstream ss;
        ss << "F" << setw(3) << setfill('0') << ++count;
        id = ss.str();
    }
    void turnOn() override {
        status = true;
        cout << "The Fan is turned on!" << endl;
    }
    void turnOff() override {
        status = false;
        cout << "The Fan is turned off!" << endl;
    }
   void showStatus() const {
    if (status)
        cout << "The device is ON" << endl;
    else
        cout << "The device is OFF" << endl;
}

    double calculatePowerUsage(int hours) override {
        power = powerRating * hours * speedFactor;
        return power;
    }
    void display() const override {
        cout << "Device Type: " << deviceType << endl;
        cout << "Device ID: " << id << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Speed Factor: "<< speedFactor<<endl;
    }
  
};
int Fan::count = 0;

class AC : public Electronics{
private:
     static int count;      // AC ka counter hai 
    string id;             // aur har AC object ki unique ID hai.
public:
    double power;
    float currentTemp;
    float desiredTemp;
     AC(double rating, bool s, float c, float d) : Electronics("AC", rating, s) , currentTemp(c) , desiredTemp(d) {
        // Ye unique IDs banai ga is tarah se F001, F002, F003 and etc.
        stringstream ss;
        ss << "AC" << setw(3) << setfill('0') << ++count;
        id = ss.str();
    }
    void turnOn() override {
        status = true;
        cout << "The AC is turned on!" << endl;
    }
    void turnOff() override {
        status = false;
        cout << "The AC is turned off!" << endl;
    }
   void showStatus() const {
    if (status)
        cout << "The AC is ON" << endl;
    else
        cout << "The AC is OFF" << endl;
}

    double calculatePowerUsage(int hours) override {
        power = (powerRating * hours * (1 - (currentTemp - desiredTemp) / 100));
        return power;
    }
    void display() const override {
        cout << "Device Type: " << deviceType << endl;
        cout << "Device ID: " << id << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Current temperature: "<<currentTemp<<endl;
        cout << "Desired Temperature: "<<desiredTemp<<endl;
    }
  
};
int AC :: count = 0;
class MaintenanceTool; // Maintenance ki class forward declaration hogi.

class SecuritySystem : public Electronics {
private:
    static int count;
    string id;
    bool alertActive;

    friend void accessSecurityLogs(const SecuritySystem&, const string&);
    friend class MaintenanceTool;

public:
    SecuritySystem(double rating, bool s, bool alert)
        : Electronics("Security System", rating, s), alertActive(alert) {
        stringstream ss;
        ss << "SEC" << setw(3) << setfill('0') << ++count;
        id = ss.str();
    }

    void turnOn() override {
        status = true;
        cout << "Locked " << id << " armed.\n";
    }

    void turnOff() override {
        cout << "Sorry, Access Denied! Only authorized maintenance can turn off " << id << endl;
    }

    double calculatePowerUsage(int hours) override {
        return powerRating * hours + (alertActive ? 50 : 10); 
    }

    void display() const override {
        cout << "[Security] ID: " << id << ", Status: " << (status ? "Active" : "Inactive")
             << ", Alert: " << (alertActive ? "Yes" : "No") << endl;
    }
};
int SecuritySystem::count = 0;

// Friend function ka task.
void accessSecurityLogs(const SecuritySystem& sec, const string& role) {
    if (role == "Maintenance") {
        cout << " Security Logs: Device ID check → OK, Alert: "
             << (sec.alertActive ? "ACTIVE" : "NORMAL") << endl;
    } else {
        cout << " Unauthorized access attempt blocked!\n";
    }
}

// Friend class ka task
class MaintenanceTool {
public:
    void resetAlerts(SecuritySystem& sec) {
        sec.alertActive = false;
        cout << "Alerts reset successfully for " << sec.deviceType << endl;
    }
};

class User {
public:
    string userID;
    string role;
    int accessLevel;

    User(string id, string r, int lvl) : userID(id), role(r), accessLevel(lvl) {}

    void viewAccessibleDevices(const vector<Electronics*>& devices) {
        cout << "\n Accessible Devices for User: " << userID << " (" << role << ")"<<endl;
        for (auto dev : devices) {
            if (dev->deviceType == "Security System" && accessLevel < 5) continue;
            dev->display();
        }
    }
};

int main() {
    LED led1(10.5, false);
    LED led2(12.0, true);
    LED led3(8.0, false);
    cout<<endl;
    led1.display();
    led2.display();
    led3.display();
    cout<<endl;
    Fan fan1(50.0, false,3);
    Fan fan2(75.0, true, 5);
    cout << endl;
    fan1.display();
    fan2.display();

    cout << endl;
    AC Ac1( 3500, true, 27, 16);
    Ac1.display();

    SecuritySystem sec1(100, true, true);

    vector<Electronics*> devices = { &led1, &led2, &led3, &fan1, &fan2, &Ac1, &sec1 };

    User user1("U001", "Regular", 1);
    User user2("M001", "Maintenance", 5);

    user1.viewAccessibleDevices(devices);
    user2.viewAccessibleDevices(devices);

    cout << endl;
    accessSecurityLogs(sec1, user1.role);  // unauthorized
    accessSecurityLogs(sec1, user2.role);  // authorized

    MaintenanceTool tool;
    tool.resetAlerts(sec1);
    
    return 0;
}
