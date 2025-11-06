// Given a Doubly linked list containing n nodes. The task is to reverse every group of k
// nodes in the list. If the number of nodes is not a multiple of k then left-out nodes, in the
// end should be considered as a group and must be reversed.
// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
// Example 1:
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 2
// Output: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5 <-> NULL.
// Example 2:
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 4
// Output: 4 <-> 3 <-> 2 <-> 1 <-> 6 -> 5 <-> NULL. 

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

    Node* reverseInGroups(Node* head, int k) {
        if (!head) return NULL;
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) {
            head->next = reverseInGroups(next, k);
            if (head->next) head->next->prev = head;
        }
        return prev;
    }

    void reverseGroups(int k) {
        head = reverseInGroups(head, k);
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }
};

int main() {
    DoublyList d;
    d.insertLast(1);
    d.insertLast(2);
    d.insertLast(3);
    d.insertLast(4);
    d.insertLast(5);
    d.insertLast(6);

    int k = 2;
    d.reverseGroups(k);
    d.display();

    DoublyList d2;
    d2.insertLast(1);
    d2.insertLast(2);
    d2.insertLast(3);
    d2.insertLast(4);
    d2.insertLast(5);
    d2.insertLast(6);

    k = 4;
    d2.reverseGroups(k);
    d2.display();
}
