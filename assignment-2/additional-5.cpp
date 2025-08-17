// 5) Given a fixed-length integer array arr, duplicate each occurrence of two (2), shifting the
// remaining elements to the right.
// Note that elements beyond the length of the original array are not written. Do the above
// modifications to the input array in place and do not return anything.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 2) {
            
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            
            if (i + 1 < n) {
                arr[i + 1] = 2;
            }
            i--; 
        }
    }

    cout << "Array after duplicating 2s: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
