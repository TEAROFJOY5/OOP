#include <iostream>
#include <iomanip> // setw(), setfll(char a) is header fill mein mujood hein.
#include <sstream>
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
    void turnOn() {
        status = true;
        cout << "The device turned on!" << endl;
    }
    void turnOff() {
        status = false;
        cout << "The device turned off!" << endl;
    }
    void Status() const {
    if (status)
        cout << "The device is ON" << endl;
    else
        cout << "The device is OFF" << endl;
}

    double calculatePowerUsage(int hours) {
        power = powerRating * hours;
        return power;
    }
    void display() const {
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
     Fan(double rating, bool s, int sf) : Electronics("Fan", rating, s) , speedFactor(s) {
        // Ye unique IDs banai ga is tarah se F001, F002, F003 and etc.
        stringstream ss;
        ss << "F" << setw(3) << setfill('0') << ++count;
        id = ss.str();
    }
    void turnOn() {
        status = true;
        cout << "The Fan is turned on!" << endl;
    }
    void turnOff() {
        status = false;
        cout << "The Fan is turned off!" << endl;
    }
   void showStatus() const {
    if (status)
        cout << "The device is ON" << endl;
    else
        cout << "The device is OFF" << endl;
}

    double calculatePowerUsage(int hours) {
        power = powerRating * hours * speedFactor;
        return power;
    }
    void display() const {
        cout << "Device Type: " << deviceType << endl;
        cout << "Device ID: " << id << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
  
};
int Fan::count = 0;

class AC : public Electronics{
private:
     static int count;      // AC ka counter hai 
    string id;             // aur har AC object ki unique ID hai.
public:
double power;
     AC(double rating, bool s) : Electronics("AC", rating, s) {
        // Ye unique IDs banai ga is tarah se F001, F002, F003 and etc.
        stringstream ss;
        ss << "AC" << setw(3) << setfill('0') << ++count;
        id = ss.str();
    }
    void turnOn() {
        status = true;
        cout << "The Fan is turned on!" << endl;
    }
    void turnOff() {
        status = false;
        cout << "The Fan is turned off!" << endl;
    }
   void showStatus() const {
    if (status)
        cout << "The device is ON" << endl;
    else
        cout << "The device is OFF" << endl;
}

    double calculatePowerUsage(int hours) {
        power = powerRating * hours;
        return power;
    }
    void display() const {
        cout << "Device Type: " << deviceType << endl;
        cout << "Device ID: " << id << endl;
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
  
};
int AC :: count = 0;
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
    AC Ac1( 3500, true);
    Ac1.display();
    

    return 0;
}
