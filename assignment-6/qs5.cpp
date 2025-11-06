// Write a program to check if a linked list is Circular Linked List or not.
// example 2 4 6 7 5

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

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);
    
    // Uncomment below line to make it circular
    // head->next->next->next->next->next = head;

    if (isCircular(head))
        cout << "Circular Linked List";
    else
        cout << "Not Circular Linked List";
}
