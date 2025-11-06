// Given a Circular linked list. The task is split into two Circular Linked lists. If there are an
// odd number of nodes in the given circular linked list then out of the resulting two halved
// lists, the first list should have one node more than the second list. 

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
public:
    Node* last;
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

    void display(Node* lastNode) {
        if (!lastNode) return;
        Node* temp = lastNode->next;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != lastNode->next) cout << " -> ";
        } while (temp != lastNode->next);
        cout << endl;
    }

    void splitList(Node*& last1, Node*& last2) {
        if (!last || last->next == last) {
            last1 = last;
            last2 = NULL;
            return;
        }

        Node* slow = last->next;
        Node* fast = last->next;

        while (fast->next != last->next && fast->next->next != last->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast->next->next == last->next)
            fast = fast->next;

        last1 = last->next;
        last2 = slow->next;

        fast->next = last2;
        slow->next = last1;
    }
};

int main() {
    CircularList c;
    c.insertLast(10);
    c.insertLast(4);
    c.insertLast(9);

    Node* last1 = NULL;
    Node* last2 = NULL;

    c.splitList(last1, last2);

    cout << "First half: ";
    c.display(last1);
    cout << "Second half: ";
    c.display(last2);
}
