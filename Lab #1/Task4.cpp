#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the arrays: ";
    cin >> size;

    int arr1[100], arr2[100]; 
    cout << "Enter elements for the first array:" << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr1[i];
    }
   cout << "Enter elements for the second array:" << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr2[i];
    }
    
    for(int i = 0; i < size; i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
    cout << "\nFirst array after swapping: ";
    for(int i = 0; i < size; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nSecond array after swapping: ";
    for(int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Step 3: Find largest in first array
    int largest = arr1[0];
    for(int i = 1; i < size; i++) {
        if(arr1[i] > largest) {
            largest = arr1[i];
        }
    }
    cout << "\nLargest element in the first array: " << largest << endl;
    int max1 = arr2[0];
    int max2 = -1;

    for(int i = 1; i < size; i++) {
        if(arr2[i] > max1) {
            max2 = max1;
            max1 = arr2[i];
        }
        else if(arr2[i] > max2 && arr2[i] != max1) {
            max2 = arr2[i];
        }
    }
    if(max2 == -1) {
        cout << "No second largest element found in the second array (all elements same)." << endl;
    } else {
        cout << "Second largest element in the second array: " << max2 << endl;
    }
    int unique = -1;
    bool foundUnique = false;
    for(int i = 0; i < size; i++) {
        int count = 0;
        for(int j = 0; j < size; j++) {
            if(arr1[i] == arr1[j]) {
                count++;
            }
        }
        if(count == 1) {
            unique = arr1[i];
            foundUnique = true;
            break;
        }
    }
    if(foundUnique) {
        cout << "Unique element in the first array: " << unique << endl;
    } else {
        cout << "All elements are unique. Returning element at index 0: " << arr1[0] << endl;
    }
    return 0;
}
