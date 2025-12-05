#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

// Abstract base class hai
class DroneBase {
private:
    string droneID;

protected:
    static int counter;

    // Function se ID generate karwai hai.
    string generateID() {
        stringstream ss;
        ss << "D" << setw(3) << setfill('0') << counter++;
        return ss.str();
    }

public:
    DroneBase() {
        droneID = generateID();
        cout << "\n[Drone Created] ID = " << droneID << "\n";
    }

    string getDroneID() {
        return droneID;
    }

    virtual void navigate() = 0;
    virtual void deliverPackage() = 0;
    virtual void selfCheck() = 0;

    virtual ~DroneBase() {}
};

// Initialize static counter
int DroneBase::counter = 1;


class IThermalScan {
public:
    virtual void thermalScan() = 0;
};

class INightVision {
public:
    virtual void nightVisionMode() = 0;
};

class DroneBasic : public DroneBase {
public:
    DroneBasic() : DroneBase() {
        cout << "DroneBasic Initialized | ID = " << getDroneID() << "\n";
    }

    void navigate() override {
        cout << getDroneID() << ": Basic Drone navigating normally...\n";
    }

    void deliverPackage() override {
        cout << getDroneID() << ": Basic Drone delivering package...\n";
    }

    void selfCheck() override {
        cout << getDroneID() << ": Basic Drone running basic diagnostics...\n";
    }
};

class DroneThermal : public DroneBase, public IThermalScan {
public:
    DroneThermal() : DroneBase() {
        cout << "DroneThermal Initialized | ID = " << getDroneID() << "\n";
    }

    void navigate() override {
        cout << getDroneID() << ": Thermal Drone navigating with heat-awareness...\n";
    }

    void deliverPackage() override {
        cout << getDroneID() << ": Thermal Drone delivering package...\n";
    }

    void selfCheck() override {
        cout << getDroneID() << ": Thermal Drone performing heat sensor diagnostics...\n";
    }

    void thermalScan() override {
        cout << getDroneID() << ": Performing thermal body-heat scan...\n";
    }
};

class DroneNightVision : public DroneBase, public INightVision {
public:
    DroneNightVision() : DroneBase() {
        cout << "DroneNightVision Initialized | ID = " << getDroneID() << "\n";
    }

    void navigate() override {
        cout << getDroneID() << ": NightVision Drone navigating in low light...\n";
    }

    void deliverPackage() override {
        cout << getDroneID() << ": NightVision Drone delivering package at night...\n";
    }

    void selfCheck() override {
        cout << getDroneID() << ": NightVision Drone running night-vision diagnostics...\n";
    }

    void nightVisionMode() override {
        cout << getDroneID() << ": NightVision mode activated...\n";
    }
};

class DronePro : public DroneBase, public IThermalScan, public INightVision {
public:
    DronePro() : DroneBase() {
        cout << "DronePro Initialized | ID = " << getDroneID() << "\n";
    }

    void navigate() override {
        cout << getDroneID() << ": DronePro navigating with full capabilities...\n";
    }

    void deliverPackage() override {
        cout << getDroneID() << ": DronePro delivering package with maximum safety...\n";
    }

    void selfCheck() override {
        cout << getDroneID() << ": DronePro performing full system diagnostics...\n";
    }

    void thermalScan() override {
        cout << getDroneID() << ": DronePro performing advanced thermal scan...\n";
    }

    void nightVisionMode() override {
        cout << getDroneID() << ": DronePro night-vision engaged...\n";
    }
};

int main()
{
  // POLYMORPHISM DEMO WITH DRONE IDs
    DroneBase* ptr;

    DroneBasic b;
    ptr = &b;
    (*ptr).navigate();
    (*ptr).deliverPackage();
    (*ptr).selfCheck();

    DroneThermal t;
    ptr = &t;
    (*ptr).navigate();
    (*ptr).selfCheck();
    t.thermalScan();  

    DroneNightVision n;
    ptr = &n;
    (*ptr).navigate();
    n.nightVisionMode();  

    DronePro p;
    ptr = &p;
    (*ptr).navigate();
    (*ptr).selfCheck();
    p.thermalScan();
    p.nightVisionMode();

    return 0;
}
