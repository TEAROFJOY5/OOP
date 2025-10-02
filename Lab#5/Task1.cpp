#include<iostream>
using namespace std;

class PetrolPump
{
  public:
   static float pricePerLiter;
   int pumpsID;
   float litersFiled;
   
   
   void printReciept(float litersFiled)
   {
       cout<<"The total Petrol cost is "<<pricePerLiter * litersFiled<<endl;
   }
};

float PetrolPump:: pricePerLiter = 270.23;
int main()
{
    PetrolPump pump1;
    pump1.pumpsID = 234234;
    cout<<"Enter the total liters filled: ";
    cin>>pump1.litersFiled;
    cout<<"\n";
    pump1.printReciept(pump1.litersFiled);
}
