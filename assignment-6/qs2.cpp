// Display all the node values in a circular linked list, repeating value of head node at the
// end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* last;
public:
    CircularList() {
        last = NULL;
    }

    void insertLast(int val) {
        Node* n = new Node(val);
        if (!last) {
            last = n;
            last->next = last;
            return;
        }
        n->next = last->next;
        last->next = n;
        last = n;
    }

    void display() {
        if (!last) return;
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << last->next->data << endl;
    }
};

int main() {
    CircularList c;
    c.insertLast(20);
    c.insertLast(100);
    c.insertLast(40);
    c.insertLast(80);
    c.insertLast(60);
    c.display();
}
