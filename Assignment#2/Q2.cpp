#include <iostream>
#include <string>
using namespace std;


class Robot {
protected:
    int id;
    float x, y;

public:
    Robot(int id, double x, double y) 
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    virtual void showInfo() const {
        cout << "Robot ID: " << id << endl;
        cout << "Position: ( "<< x << " , " << y << " )" << endl;
    }

    virtual void performTask() const = 0;

    virtual ~Robot() 
    {
       // cout<<"Destructor Called.."<<endl;
    }
};
class AssemblyRobot : public Robot {
    int speed; 
public:
    AssemblyRobot(int id, float x, float y, int speed)
        : Robot(id, x, y) 
        {
            this->speed = speed ;
        }

    void performTask() const override {
        cout << "Assembly_Robot " << id
             << " assembling at " << speed << " units/minute." << endl;
    }
};
class WeldingRobot : public Robot {
    float temp; 
public:
    WeldingRobot(int id, float x, float y, float temp)
        : Robot(id, x, y)
        {
           this->temp = temp ;   
        }

    void performTask() const override {
        cout << "Welding_Robot " << id
             << " welding at " << temp << "°C." << endl;
    }
};
class PaintingRobot : public Robot {
    string colour;
public:
    PaintingRobot(int id, float x, float y, string colour)
        : Robot(id, x, y)
        {
            this->colour = colour;
        }

    void performTask() const override {
        cout << "Painting_Robot " << id
             << " painting with colour " << colour << "." << endl;
    }
};
int main() {
    cout<<"Turab Ali 24k-0651"<<endl;
    AssemblyRobot a1(1, 64.5, 62.5, 70);
    WeldingRobot w1(25, 267.2, 32.3, 2000.0);
    PaintingRobot p1(99, 23.0, 82.0, "Green");
    Robot* robots[] = { &a1, &w1, &p1 };

    for (Robot* r : robots) {
        (*r).showInfo();
        
        (*r).performTask();
    }

    return 0;
}
