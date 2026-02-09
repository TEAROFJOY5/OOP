#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;
class Student{
  private:
    static int count;
    string name;
    int age;
    string rollNo;
  protected:
    float mid1Marks;
    float mid2Marks;
    float finalMarks;
    float total;
  public:
  Student(string n, int a) : name(n), age(a){
    stringstream ss;
    ss<< "26Q-" << setw(4) << setfill('0') << ++count ;
    rollNo = ss.str();
  }
  void setAge(int a)
  {
      age = a;
  }
  int getAge()
  {
      return age;
  }
  void setName(string n)
  {
      name = n;
  }
  const char* getName()
  {
      return name.c_str(); /* const char* c_str() const;
It returns a pointer to a C-style string (const char*) that represents the same text stored in the std::string.
  */
  }
  Student(){
    name = "Peter";
    age = 21;
    stringstream ss;
    ss<< "26Q-" << setw(4) << setfill('0') << ++count ;
    rollNo = ss.str();
  }
  void displayDetails(){
      cout<<"Name: "<<name<<endl
          <<"Age; "<<age<<endl
          <<"Roll No: "<<rollNo<<endl;
  }
};
int Student :: count = 0;
class marks : public Student {
  public:
    void mid1(float x) {
        while (x > 15) {
            cout << "Enter again: " << endl;
            cin >> x;
        }
        mid1Marks = x;
    }

    void mid2(float x) {
        while (x > 15) {
            cout << "Enter again: " << endl;
            cin >> x;
        }
        mid2Marks = x;
    }

    void calculateTotal() {
        total = mid1Marks + mid2Marks;
    }
};

int main()
{
    Student s1("Turab", 20);
    s1.displayDetails();
    cout<<"\n";
    Student s;
    s.displayDetails();
}
