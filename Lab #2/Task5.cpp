#include <iostream>
#include <cstring>   
#include <limits>
using namespace std;

int main() {
    int size1, size2;
    cout << "Enter the size of the 1st String: ";
    cin>>size1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char *str1 = new char[size1 + 1];   
    cout << "\nEnter the first string: ";
    cin.getline(str1, size1 + 1);
    cout << "\nEnter the size of the 2nd String: ";
     cin>>size2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char *str2 = new char[size2 + 1];
    cout << "Enter the second string: ";
    cin.getline(str2, size2 + 1);
    char *concat = new char[size1 + size2 + 1];
    strcpy(concat, str1);
    strcat(concat, str2);
    cout << "\nFirst String: " << str1 << endl;
    cout << "Second String: " << str2 << endl;
    cout << "Concatenated String: " << concat << endl;
  
    delete[] str1;
    delete[] str2;
    delete[] concat;

  
}
