// 1) Develop a Menu driven program to demonstrate the following operations of Arrays 
// ——MENU——-
// 1.CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT

#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX], n = 0;

// Function to create array
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Function to display array
void display() {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert element
void insertElement() {
    int pos, value;
    if (n == MAX) {
        cout << "Array is full, cannot insert!" << endl;
        return;
    }
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    cout << "Element inserted successfully!" << endl;
}

// Function to delete element
void deleteElement() {
    int pos;
    if (n == 0) {
        cout << "Array is empty, nothing to delete!" << endl;
        return;
    }
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted successfully!" << endl;
}

// Function for linear search
void linearSearch() {
    int key, found = -1;
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1)
        cout << "Element found at position " << found + 1 << endl;
    else
        cout << "Element not found!" << endl;
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n---- MENU ----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

