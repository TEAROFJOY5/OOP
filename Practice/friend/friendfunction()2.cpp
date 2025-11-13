#include<iostream>
using namespace std;
class student;
void grade(student &obj);
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
 friend void grade(student &obj);
};
void grade(student &obj){
  // student s;
   //int m = s.marks;
    if( obj.marks <= 50)
    {
        cout<<"you failed. You grade is "<<obj.marks<<endl;
    }
}
int main()
{
    student s1;
    grade( s1);
}
