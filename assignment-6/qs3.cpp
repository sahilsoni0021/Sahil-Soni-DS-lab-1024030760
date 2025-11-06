// Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
public:
    DoublyList() {
        head = NULL;
    }

    void insertLast(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
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
            n->next = n;
            return;
        }
        n->next = last->next;
        last->next = n;
        last = n;
    }

    int size() {
        if (!last) return 0;
        int count = 0;
        Node* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }
};

int main() {
    DoublyList d;
    CircularList c;

    d.insertLast(10);
    d.insertLast(20);
    d.insertLast(30);

    c.insertLast(5);
    c.insertLast(15);
    c.insertLast(25);
    c.insertLast(35);

    cout << "Size of Doubly Linked List: " << d.size() << endl;
    cout << "Size of Circular Linked List: " << c.size() << endl;
}
