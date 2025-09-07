#include<iostream>
using namespace std;
int main()
{
    int arr[10] = {5000, 1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int num[10] = {0};  
    int money;
    cout << "Enter the currency at hand: ";
    cin >> money;
    for(int i = 0; i < 10; i++) {
        if(money >= arr[i]) {
            num[i] = money / arr[i];      
            money = money % arr[i];       
        }
    }
    cout << "Minimum notes required are:\n";
    for(int i = 0; i < 10; i++) {
        if(num[i] > 0) {
            cout << arr[i] << " x " << num[i] << endl;
        }
    }
    return 0;
}

