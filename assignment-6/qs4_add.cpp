// Given a doubly linked list having exactly one of the node pointing to a random node in the
// list, the task is to correct this random pointer in the doubly linked list, such that it points to
// the expected node.
// https://www.geeksforgeeks.org/correct-the-random-pointer-in-doubly-linked-list/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random;
    Node(int val) {
        data = val;
        next = prev = random = NULL;
    }
};

class DoublyList {
public:
    Node* head;
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

    void correctRandom() {
        Node* temp = head;
        Node* wrong = NULL;
        while (temp) {
            if (temp->random && temp->random->prev != temp && temp->random->next != temp)
                wrong = temp;
            temp = temp->next;
        }
        if (!wrong) return;

        Node* x = head;
        while (x->next) x = x->next;
        wrong->random = x;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void showRandom() {
        Node* temp = head;
        while (temp) {
            cout << "Node " << temp->data << " random -> ";
            if (temp->random) cout << temp->random->data;
            else cout << "NULL";
            cout << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyList d;
    d.insertLast(1);
    d.insertLast(2);
    d.insertLast(3);
    d.insertLast(4);
    d.insertLast(5);

    d.head->random = d.head->next;
    d.head->next->random = d.head;
    d.head->next->next->random = d.head->next->next->next;
    d.head->next->next->next->random = d.head->next; 
    d.head->next->next->next->next->random = NULL;

    cout << "Before correction:" << endl;
    d.showRandom();

    d.correctRandom();

    cout << "\nAfter correction:" << endl;
    d.showRandom();
}
