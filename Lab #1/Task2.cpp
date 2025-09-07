#include<iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Enter the number of rows"<<endl;
    cin>>rows;
    for(int i=1; i<=rows; i++)
    {
        for(int j= rows; j >= i; j--)
        {
            cout<<" ";
        }
      char ch = 'A';
      for(int r = 1; r<=  2*i - 1 ; r++ )
      {
          cout<<ch;
          ch++;
      }
      cout<<endl;
        
    }
    
    for(int i=rows-1; i>=1; i--)
    {
        for(int j= i; j <= rows; j++)
        {
            cout<<" ";
        }
      char ch = 'A';
      for(int r = 2*i - 1; r>=1   ; r-- )
      {
          cout<<ch;
          ch++;
      }
      cout<<endl;
        
    }
    
    return 0;
}
