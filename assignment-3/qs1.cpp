// Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include <iostream>
using namespace std;

#define MAX 5   

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // (vi) Peek operation (view top element)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is not empty.\n";
            break;

        case 4:
            if (s.isFull())
                cout << "Stack is full.\n";
            else
                cout << "Stack is not full.\n";
            break;

        case 5:
            s.display();
            break;

        case 6:
            s.peek();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
