#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of the square matrix (N): ";
    cin >> N;
    int **matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    cout << "Enter elements of the matrix (" << N*N << " numbers):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    int mainDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < N; i++) {
        mainDiagonalSum += matrix[i][i];             
        secondaryDiagonalSum += matrix[i][N - i - 1]; 
    }
    cout << "\nMatrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nSum of Main Diagonal = " << mainDiagonalSum << endl;
    cout << "Sum of Secondary Diagonal = " << secondaryDiagonalSum << endl;
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

}
