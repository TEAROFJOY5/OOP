#include <iostream>
#include <string>
using namespace std;

class Battery {
    int capacity;
    int level;
public:
    Battery() {
        capacity = 100;
        level = 100;
    }
    Battery(int capacity, int level) {
        this->capacity = capacity;
        this->level = level;
    }
    int getLevel() const {
        return level;
    }
    void setLevel(int level) {
        if (level >= 0 && level <= capacity) 
        {
            this->level = level;
        }
    }
    void recharge() {
        level = capacity;
        cout << "Battery fully recharged to the level " << level << "%" << endl;
    }
    void recharge(int amount) {
        level += amount;
        if (level > capacity) level = capacity;
        cout << "Battery partially recharged to " << level << "%" << endl;
    }
};

class Robot {
private:
    string name;
    string modelID;
    Battery battery;
public:
    Robot(string name, string modelID, int batteryLevel) : battery(100, batteryLevel) {
        this->name = name;
        this->modelID = modelID;
    }
    string getName() const {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    string getModelID() const {
        return modelID;
    }
    void setModelID(string modelID) {
        this->modelID = modelID;
    }
    int getBatteryLevel() const {
        return battery.getLevel();
    }
    void rechargeBattery() {
        battery.recharge();
    }
    void rechargeBattery(int amount) {
        battery.recharge(amount);
    }
    virtual void showDetails() const {
        cout << "Robot Name: " << name << endl;
        cout << "Model ID: " << modelID << endl;
        cout << "Battery Level: " << battery.getLevel() << "%" << endl;
    }
    virtual ~Robot() {}
};

class TeachingBot : public Robot {
    string subject;
    float bonusPerClass;
    int classesTaught;
public:
    TeachingBot(string name, string modelID, int batteryLevel, string subject, float bonus, int classes)
        : Robot(name, modelID, batteryLevel) {
        this->subject = subject;
        this->bonusPerClass = bonus;
        this->classesTaught = classes;
    }
    void showDetails() const override {
        Robot::showDetails();
        cout << "Subject: " << subject << endl;
        cout << "Classes Taught: " << classesTaught << endl;
        cout << "Bonus Earned: " << bonusPerClass * classesTaught << endl;
    }
};

class MaintenanceBot : public Robot {
    int overtimeHours;
    float ratePerHour;
public:
    MaintenanceBot(string name, string modelID, int batteryLevel, int hours, float rate)
        : Robot(name, modelID, batteryLevel) {
        this->overtimeHours = hours;
        this->ratePerHour = rate;
    }
    void showDetails() const override {
        Robot::showDetails();
        cout << "Overtime Hours: " << overtimeHours << endl;
        cout << "Rate per Hour: " << ratePerHour << endl;
        cout << "Overtime Pay: " << overtimeHours * ratePerHour << endl;
    }
};

int main() {
    cout << "Turab Ali 24k-0651" << endl << endl;

    TeachingBot T("Sir baqir", "cal-2001", 85, "Mathematics", 370.0, 3);
    MaintenanceBot M("helper ", "mvc-1002", 60, 5, 200.0);

    Robot* r1 = new TeachingBot("Edu", "ap-305", 75, "Physics", 400.0, 2);
    Robot* r2 = new MaintenanceBot("Jolly", "MB-450", 50, 8, 250.0);

    T.showDetails();
    cout << endl;
    M.showDetails();
    cout << endl;
    r1->showDetails();
    cout << endl;
    r2->showDetails();
    cout << endl;

    T.rechargeBattery(10);
    M.rechargeBattery();
    cout << endl;

    delete r1;
    delete r2;

    return 0;
}
