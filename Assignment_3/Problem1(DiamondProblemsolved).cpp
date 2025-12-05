#include<iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class systemCore {
public:
    static int sCount;
    static int fCount;

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

class sensorModule : virtual public systemCore {
private:
    bool ifObstacle;
    double temp;
    int eyeSight;

public:
    sensorModule()
    {
        ifObstacle = true;
        temp = 25.0;
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

    void statusReport() override {
        cout << "\n[SensorModule Report]\n";
        cout << "System ID: " << getSystemID() << endl;
        cout << "Obstacle detected: " << (ifObstacle ? "Yes" : "No") << endl;
        cout << "Temperature: " << temp << endl;
        cout << "EyeSight Range: " << eyeSight << " meters\n";
    }
};

class controlModule : virtual public systemCore {
private:
    float horsePower;
    double speed;
    double brakeForce;

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
        : systemCore()
    {
        botName = "Peter";
        batteryLevel = 100.0;
        operationMode = "Idle";
    }

    autoBot(string n, double b, string o)
        : systemCore(), botName(n), batteryLevel(b), operationMode(o)
    {}

    void statusReport() override {
        cout << "\n[AutoBot Report]\n";
        cout << "Bot Name: " << botName << endl;
        cout << "Battery: " << batteryLevel << "%" << endl;
        cout << "Mode: " << operationMode << endl;
        cout << "System ID: " << getSystemID() << endl;
        cout << "Firmware: " << getFirmwareUpdate() << endl;
    }
};

int main()
{
    systemCore s1;
    sensorModule sm(false, 32, 20);
    controlModule cm(4.0, 5.5, 200);
    autoBot bot1("Alpha", 85, "Patrolling");

    systemCore* ptr;
    ptr = &sm;
    ptr->statusReport();

    ptr = &cm;
    ptr->statusReport();

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
