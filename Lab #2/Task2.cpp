#include<iostream>
using namespace std;
void FirstAndLastIndex(string str, char ch, int *firstPtr, int *lastPtr);
int main ()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin, str); 
    char ch;
    cout<<"\nEnter the character you are looking in this string:";
    cin>>ch;
    int a = 0 , b = 0 ;
    int *firstPtr = &a ;
    int *lastPtr = &b ;
    FirstAndLastIndex(str,ch,firstPtr, lastPtr);
    if( *firstPtr == -1 && *lastPtr == -1)
      cout<<ch<<" doesn't exist in this string."<<endl;
    else
     { 
      cout<<ch<<" 1st exist in this string in the index of "<<*firstPtr<<endl;
      cout<<ch<<" last exist in this string in the index of "<<*lastPtr<<endl;
     } 
    
}
void FirstAndLastIndex(string str, char ch, int *firstPtr, int *lastPtr)
{
     *firstPtr = -1 ;
     *lastPtr = -1 ;
    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
        {  
            if(*firstPtr == -1)
            {
             *firstPtr = i ;
            }
            *lastPtr = i ;
        }
    }
}
