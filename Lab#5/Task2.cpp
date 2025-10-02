#include <iostream>
using namespace std;

class MobileDevice {
  private:
       string modelName;
       const string IMEINumber;
     
  public:
       MobileDevice(const string& MODEL, const string& IMEI) : modelName(MODEL), IMEINumber(IMEI) {}

       void verifyDevice() const {
           cout << "Model Name: " << modelName << endl;
           cout << "IMEI Number: " << IMEINumber << endl;
            } 
};

int main() {
    MobileDevice set("Infinix Note 30", "234234133423468");
    set.verifyDevice();

    return 0;
}
