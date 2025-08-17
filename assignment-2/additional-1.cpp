// 1) Find two numbers in an array whose difference equals K. Given an array arr[] and a positive
// integer k, the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j])
// is equal to k.

#include <iostream>
#include <algorithm>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k) {
    sort(arr, arr + n);  // sort the array first

    int i = 0, j = 1, count = 0;

    while (i < n && j < n) {
        int diff = arr[j] - arr[i];

        if (diff == k) {
            count++;
            i++;
            j++;
        } 
        else if (diff > k) {
            i++;
        } 
        else { // diff < k
            j++;
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Total pairs with difference " << k << " = "
         << countPairsWithDiffK(arr, n, k) << endl;

    return 0;
}
