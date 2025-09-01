// 1) Find two numbers in an array whose difference equals K. Given an array arr[] and a positive
// integer k, the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j])
// is equal to k.

#include <iostream>
#include <cmath> 
using namespace std;

int countPairs(int arr[], int n, int k) {
    int count = 0;

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Total pairs with difference " << k << " = " 
         << countPairs(arr, n, k) << endl;

    return 0;
}
