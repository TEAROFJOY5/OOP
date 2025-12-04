#include<iostream>
#include <iomanip> // setw(), setfll(char a) is header fill mein mujood hein.
#include <sstream>
using namespace std;
class systemCore{
    //Is class mein huum sarre system ID aur Firmware Update ko dekhe ge.
    public:
        static int sCount; //count hai jo system ID ko update karre ga.
        static int fCount; //count hai jo firmaware ki update ko update karre ga.
        string sysID;
        string FirmUpdate;
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
        
};
int systemCore :: sCount = 0;
int systemCore :: fCount = 0;

class sensorModule : public systemCore{
  public:  
      bool ifObstacle ; //Check if there are any obstacle in the way of the robot.
      double temp; // Sense the temperature.
      int eyeSight; //Vision range in meters
      sensorModule() //Ye default constructor hai
      {
          ifObstacle = true ;
          temp = 25.00 ;
          eyeSight = 20;
          cout<<"\nThe robot with system ID "<<sysID<<" and Firmware Update version: "<<FirmUpdate<<endl;
      }
      sensorModule(bool o, double t, int e) : ifObstacle(o), temp(t), eyeSight(e). //Ye parametric constructor hai.
      {
          cout<<"\nThe robot with system ID "<<sysID<<" and Firmware Update version: "<<FirmUpdate<<endl;
      }
};
class controlModule : public systemCore{
    public:
        float horsePower;
        double speed; //speed in km/s
        double brakeForce; // in Newton ( N ).
       controlModule()
       {
           horsePower = 2.4;
           speed = 4.99;
           brakeForce = 250;
           cout<<"\nThe robot with system ID "<<sysID<<" and Firmware Update version: "<<FirmUpdate<<endl;
       }
       controlModule(float h, double s, double b) : horsePower(h), speed(s), brakeForce(b)
       {
           cout<<"\nThe robot with system ID "<<sysID<<" and Firmware Update version: "<<FirmUpdate<<endl;
       }
};
class autoBot : public sensorModule, public controlModule {
    public:
        
    
};
int main()
{
    systemCore s1;
    cout<<s1.sysID<<endl<<s1.FirmUpdate;
    sensorModule sm(false, 32, 20.00);
    sensorModule sm1;
    
}
