#include<iostream>
#include <iomanip> // setw(), setfll(char a) is header fill mein mujood hein.
#include <sstream>
using namespace std;

//Is class mein huum sarre system ID aur Firmware Update ko dekhe ge.
class systemCore {
public:
    static int sCount;  //count hai jo system ID ko update karre ga.
        static int fCount; //count hai jo firmaware ki update ko update karre ga.
  

private:
    string sysID;
    string FirmUpdate;

public:
    systemCore()
    {
        stringstream ss;
        ss<<"S"<< setw(3)<< setfill('0')<< ++sCount;
        sysID = ss.str();

        stringstream ff;
        ff<< "F" << setw(3) << setfill('0') << ++fCount;
        FirmUpdate = ff.str();
        //Is constructor se humne firmwareUpdate aur system ID ka count sahih rakhe ga.
           
    }

    string getSystemID() const { return sysID; }
    string getFirmwareUpdate() const { return FirmUpdate; }

    virtual void statusReport() {
        cout << "\n[SystemCore Report]\n";
        cout << "System ID: " << sysID << endl;
        cout << "Firmware: " << FirmUpdate << endl;
    }
};

int systemCore::sCount = 0;
int systemCore::fCount = 0;

class sensorModule : public systemCore {
private:
    bool ifObstacle ; //Check if there are any obstacle in the way of the robot.
      double temp; // Sense the temperature.
      int eyeSight; //Vision range in meters
public:
    sensorModule()
    {
        ifObstacle = true;
        temp = 25.00;
        eyeSight = 20;
        cout<<"\nSensorModule created with System ID: "<<getSystemID()
            <<" | Firmware: "<<getFirmwareUpdate()<<endl;
    }

    sensorModule(bool o, double t, int e)
        : ifObstacle(o), temp(t), eyeSight(e)
    {
        cout<<"\nSensorModule created with System ID: "<<getSystemID()
            <<" | Firmware: "<<getFirmwareUpdate()<<endl;
    }

    bool getObstacle() const { return ifObstacle; }
    double getTemp() const { return temp; }
    int getEyeSight() const { return eyeSight; }

    void setObstacle(bool o) { ifObstacle = o; }
    void setTemp(double t) { temp = t; }
    void setEyeSight(int e) { eyeSight = e; }

    void statusReport() override {
        cout << "\n[SensorModule Report]\n";
        cout << "System ID: " << getSystemID() << endl;
        cout << "Obstacle detected: " << (ifObstacle ? "Yes" : "No") << endl;
        cout << "Temperature: " << temp << endl;
        cout << "EyeSight Range: " << eyeSight << " meters\n";
    }
};

class controlModule : public systemCore {
private:
    float horsePower;
   double speed; //speed in km/s
        double brakeForce; // in Newton ( N ).

public:
    controlModule()
    {
        horsePower = 2.4;
        speed = 4.99;
        brakeForce = 250;
        cout<<"\nControlModule created with System ID: "<<getSystemID()
            <<" | Firmware: "<<getFirmwareUpdate()<<endl;
    }

    controlModule(float h, double s, double b)
        : horsePower(h), speed(s), brakeForce(b)
    {
        cout<<"\nControlModule created with System ID: "<<getSystemID()
            <<" | Firmware: "<<getFirmwareUpdate()<<endl;
    }
    float getHorsePower() const { return horsePower; }
    double getSpeed() const { return speed; }
    double getBrakeForce() const { return brakeForce; }

    void setHorsePower(float h) { horsePower = h; }
    void setSpeed(double s) { speed = s; }
    void setBrakeForce(double b) { brakeForce = b; }

    // Override
    void statusReport() override {
        cout << "\n[ControlModule Report]\n";
        cout << "System ID: " << getSystemID() << endl;
        cout << "Horse Power: " << horsePower << endl;
        cout << "Speed: " << speed << endl;
        cout << "Brake Force: " << brakeForce << endl;
    }
};


class autoBot : public sensorModule, public controlModule {
private:
    string botName;
    double batteryLevel;
    string operationMode;

public:
    autoBot()
    {
        botName = "Peter";
        batteryLevel = 100.00;
        operationMode = "Idle";
    }

    autoBot(string n, double b, string o)
        : botName(n), batteryLevel(b), operationMode(o)
    {}

    string getName() const { return botName; }
    double getBattery() const { return batteryLevel; }
    string getMode() const { return operationMode; }

 // override
    void statusReport() override {
        cout << "\n[AutoBot Report]\n";
        cout << "Bot Name: " << botName << endl;
        cout << "Battery: " << batteryLevel << "%" << endl;
        cout << "Mode: " << operationMode << endl;
    }
};

int main()
{
    //Stack object create kya hai.
    systemCore s1;
    sensorModule sm(false, 32, 20);
    controlModule cm(4.0, 5.5, 200);
    autoBot bot1("Alpha", 85, "Patrolling");
// Ye polymorphism howi hai
    systemCore* ptr;

    ptr = &sm;
    ptr->statusReport();

    ptr = &cm;
    ptr->statusReport();
// Ye heap object hai.
    systemCore* heapSys = new systemCore();
    sensorModule* heapSensor = new sensorModule();
    autoBot* heapBot = new autoBot("Beta", 92, "Scanning");

    cout << "\nHeap AutoBot Status:\n";
    heapBot->statusReport();

    delete heapSys;
    delete heapSensor;
    delete heapBot;

    return 0;
}
