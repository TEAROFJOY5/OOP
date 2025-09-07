#include<iostream>
using namespace std;
void multiplyMatrices(int A[10][10], int B[10][10], int C[10][10], int m, int n, int p)
{
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            C[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < p; j++) 
        {
            for(int k = 0; k < n; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int m, n, p;
    int A[10][10], B[10][10], C[10][10];

    cout << "Enter number of rows and columns for matrix A (m n): ";
    cin >> m >> n;

    cout << "Enter number of columns for matrix B (p): ";
    cin >> p;

    cout << "Enter elements of matrix A:" << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            cin >> B[i][j];
        }
    }

    
    multiplyMatrices(A, B, C, m, n, p);
    cout << "Resulting matrix after multiplication (C = A x B):" << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
