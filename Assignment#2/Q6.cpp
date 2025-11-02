#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RoboHealth {
private:
    int id;
    float temperature;
    float energyLevel;
    float efficiency;
    static int robotCount;
public:
    RoboHealth(int id, float t, float e, float ef) {
        this->id = id;
        this->temperature = t;
        this->energyLevel = e;
        this->efficiency = ef;
        robotCount++;
    }

    static void showTotalRobots() {
        cout << "Total Robots Created: " << robotCount << endl;
    }

    inline void updateReadings(float t, float e, float ef) {
        temperature = t;
        energyLevel = e;
        efficiency = ef;
    }

    inline void checkStatus() const {
        if (temperature > 80 || efficiency < 30) {
            cout << "Robot " << id << ": Critical Condition!" << endl;
        } 
        else if (temperature < 70 && energyLevel > 40) {
            cout << "Robot " << id << ": Stable" << endl;
        } 
        else {
            cout << "Robot " << id << ": Warning: Maintenance Required" << endl;
        }
    }

    void showData() const {
        cout << "Robot ID: " << id << endl;
        cout << "Temp: " << temperature << "°C" << endl;
        cout << "Energy: " << energyLevel << "%" << endl;
        cout << "Efficiency: " << efficiency << "%" << endl;
    }
};

int RoboHealth::robotCount = 0;

int main() {
    cout << "Turab Ali 24k-0651" << endl << endl;

    srand(time(0));
    const int n = 5;
    RoboHealth robots[n] = {
        RoboHealth(1, 50 + rand() % 30, 30 + rand() % 60, 40 + rand() % 50),
        RoboHealth(2, 45 + rand() % 40, 25 + rand() % 70, 35 + rand() % 60),
        RoboHealth(3, 55 + rand() % 35, 20 + rand() % 70, 20 + rand() % 60),
        RoboHealth(4, 60 + rand() % 25, 30 + rand() % 60, 25 + rand() % 50),
        RoboHealth(5, 40 + rand() % 50, 35 + rand() % 65, 30 + rand() % 60)
    };

    cout << endl;
    RoboHealth::showTotalRobots();
    cout << endl;

    robots[1].updateReadings(85, 35, 45);
    robots[3].updateReadings(65, 50, 28);

    for (int i = 0; i < n; i++) {
        robots[i].showData();
        robots[i].checkStatus();
        cout << endl;
    }

    return 0;
}
