#include<iostream>
using namespace std;
void findPrimesInRange(int start, int end)
{
    for(int i = start + 1; i < end; i++)
    {
        bool isPrime = true;

        if(i < 2) 
            continue;

        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    int start, end;
    cout << "Enter the start number: ";
    cin >> start;
    cout << "Enter the end number: ";
    cin >> end;

    cout << "Prime numbers between " << start << " and " << end << " are:" << endl;
    findPrimesInRange(start, end);

    return 0;
}
