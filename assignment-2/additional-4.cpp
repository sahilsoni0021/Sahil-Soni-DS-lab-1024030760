// 4) Sort an array of 0s, 1s and 2s - Dutch National Flag Problem
// Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e.,
// put all 0s first, then all 1s and all 2s in last.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements (only 0, 1, 2): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    
    int index = 0;
    for (int i = 0; i < count0; i++) {
        arr[index] = 0;
        index++;
    }
    for (int i = 0; i < count1; i++) {
        arr[index] = 1;
        index++;
    }
    for (int i = 0; i < count2; i++) {
        arr[index] = 2;
        index++;
    }

    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
