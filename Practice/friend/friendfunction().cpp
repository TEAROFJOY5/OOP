#include<iostream>
using namespace std;
void grade();
class student{
  private:
    int marks ;
    string name;
    public:
    student()
    {
        marks = 45;
        name = "John";
    }
 friend void grade();
};
void grade(){
   student s;
   int m = s.marks;
    if( m <= 50)
    {
        cout<<"you failed. You grade is "<<m<<endl;
    }
}
int main()
{
  grade();
}
