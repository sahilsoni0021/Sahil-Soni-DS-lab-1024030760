// 3) Given an array of n-1 distinct integers in the range of 1 to n, find the missing number
// in it in a Sorted Array
// (a) Linear time
// (b) Using binary search.

// a (O(n))
#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    int total_sum = n * (n + 1) / 2; // sum of 1..n
    int arr_sum = 0;

    for (int i = 0; i < n - 1; i++) {
        arr_sum += arr[i];
    }

    return total_sum - arr_sum;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n - 1 << " elements in sorted order: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;

    return 0;
}

// b (O(log n))
#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2; // since array has n-1 elements

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            // missing is on the right side
            low = mid + 1;
        } else {
            // missing is on the left side
            high = mid - 1;
        }
    }

    return low + 1; // missing number
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n - 1 << " elements in sorted order: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}

