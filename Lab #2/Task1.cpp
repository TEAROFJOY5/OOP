#include<iostream>
using namespace std;
void SwapValues(int *a, int *b);
int main ()
{
    int x,y;
    cout<<"Enter any 2 integers: ";
    cin>>x>>y;
    int *a = &x;
    int *b = &y;
    SwapValues(a,b);
    
    
}
void SwapValues(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    cout<<"The 1st integer is "<<*a<<endl;
    cout<<"The 2nd integer is "<<*b<<endl;
}
