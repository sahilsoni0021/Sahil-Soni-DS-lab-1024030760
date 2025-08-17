// 5) Write a program to find sum of every row and every column in a two-dimensional
// array.

#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    int A[20][20];
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }

    // Row sum
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) {
            sum += A[i][j];
        }
        cout << "Row " << i + 1 << " = " << sum << endl;
    }

    // Column sum
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            sum += A[i][j];
        }
        cout << "Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}
