// Given a Doubly linked list and Circular singly linked list containing N nodes, the task is
// to remove all the nodes from each list which contains elements whose parity is even.
//  https://www.geeksforgeeks.org/remove-all-even-parity-nodes-from-a-doubly-andcircular-singly-linked-list/
// Note: Parity means no of 1 in binary form
// 11 -> 1011, parity = 3
// 15 -> 1111, parity = 4
// Example 1:
// Input: CLL: 9 -> 11 -> 34 -> 6 -> 13 -> 21
// Output: 11 -> 13 -> 21
// Example 2:
// Input: DLL: 18 <=> 15 <=> 8 <=> 9 <=> 14
// Output: 8 <=> 14

#include <iostream>
using namespace std;

int countParity(int n) {
    int c = 0;
    while (n) {
        if (n & 1) c++;
        n >>= 1;
    }
    return c;
}

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    DNode* head;
    DoublyList() {
        head = NULL;
    }

    void insertLast(int val) {
        DNode* n = new DNode(val);
        if (!head) {
            head = n;
            return;
        }
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void removeEvenParity() {
        DNode* temp = head;
        while (temp) {
            DNode* nextNode = temp->next;
            if (countParity(temp->data) % 2 == 0) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                delete temp;
            }
            temp = nextNode;
        }
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <=> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
public:
    CNode* last;
    CircularList() {
        last = NULL;
    }

    void insertLast(int val) {
        CNode* n = new CNode(val);
        if (!last) {
            last = n;
            n->next = n;
            return;
        }
        n->next = last->next;
        last->next = n;
        last = n;
    }

    void removeEvenParity() {
        if (!last) return;
        CNode* curr = last->next;
        CNode* prev = last;
        do {
            CNode* nextNode = curr->next;
            if (countParity(curr->data) % 2 == 0) {
                if (curr == last && curr->next == last) {
                    delete curr;
                    last = NULL;
                    return;
                }
                if (curr == last) last = prev;
                prev->next = curr->next;
                if (curr == last->next) last->next = curr->next;
                delete curr;
            } else prev = curr;
            curr = nextNode;
        } while (curr != last->next);
    }

    void display() {
        if (!last) return;
        CNode* temp = last->next;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != last->next) cout << " -> ";
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularList c;
    c.insertLast(9);
    c.insertLast(11);
    c.insertLast(34);
    c.insertLast(6);
    c.insertLast(13);
    c.insertLast(21);

    DoublyList d;
    d.insertLast(18);
    d.insertLast(15);
    d.insertLast(8);
    d.insertLast(9);
    d.insertLast(14);

    cout << "Original CLL: ";
    c.display();
    c.removeEvenParity();
    cout << "After removing even parity: ";
    c.display();

    cout << "\nOriginal DLL: ";
    d.display();
    d.removeEvenParity();
    cout << "After removing even parity: ";
    d.display();
}
