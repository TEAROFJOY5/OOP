#include <iostream>
using namespace std;

int sumArray(int *arr, int size);

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);   
    }
    int result = sumArray(arr, size);
    cout << "Sum of array elements = " << result << endl;
    delete[] arr;
}
int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);   
    }
    return sum;
}
