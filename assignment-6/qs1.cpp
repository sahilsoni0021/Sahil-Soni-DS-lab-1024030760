// Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.

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

    void insertFirst(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
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

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node(val);
        n->next = temp->next;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) {
            insertFirst(val);
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node(val);
        n->prev = temp->prev;
        n->next = temp;
        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int val) {
        if (!head) return;
        Node* temp = head;
        if (temp->data == val) {
            head = temp->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }
        while (temp && temp->data != val) temp = temp->next;
        if (!temp) return;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                cout << "Found " << val << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularList {
    Node* last;
public:
    CircularList() {
        last = NULL;
    }

    void insertFirst(int val) {
        Node* n = new Node(val);
        if (!last) {
            last = n;
            n->next = n;
            return;
        }
        n->next = last->next;
        last->next = n;
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

    void insertAfter(int key, int val) {
        if (!last) return;
        Node* temp = last->next;
        do {
            if (temp->data == key) {
                Node* n = new Node(val);
                n->next = temp->next;
                temp->next = n;
                if (temp == last) last = n;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
    }

    void deleteNode(int val) {
        if (!last) return;
        Node* curr = last->next;
        Node* prev = last;
        do {
            if (curr->data == val) {
                if (curr == last && curr->next == last) {
                    delete curr;
                    last = NULL;
                    return;
                }
                if (curr == last->next) last->next = curr->next;
                if (curr == last) last = prev;
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
    }

    void search(int val) {
        if (!last) {
            cout << "Not Found" << endl;
            return;
        }
        Node* temp = last->next;
        do {
            if (temp->data == val) {
                cout << "Found " << val << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);
        cout << "Not Found" << endl;
    }

    void display() {
        if (!last) return;
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    DoublyList d;
    CircularList c;
    int choice, val, key, type;
    while (true) {
        cout << "\n1.Doubly  2.Circular  3.Exit: ";
        cin >> type;
        if (type == 3) break;
        cout << "1.InsertFirst 2.InsertLast 3.InsertAfter 4.InsertBefore 5.Delete 6.Search 7.Display 8.Back\n";
        while (true) {
            cout << "Enter choice: ";
            cin >> choice;
            if (choice == 8) break;
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val;
                        if (type == 1) d.insertFirst(val); else c.insertFirst(val);
                        break;
                case 2: cout << "Enter value: "; cin >> val;
                        if (type == 1) d.insertLast(val); else c.insertLast(val);
                        break;
                case 3: cout << "Enter key and value: "; cin >> key >> val;
                        if (type == 1) d.insertAfter(key, val); else c.insertAfter(key, val);
                        break;
                case 4: cout << "Enter key and value: "; cin >> key >> val;
                        if (type == 1) d.insertBefore(key, val);
                        break;
                case 5: cout << "Enter value: "; cin >> val;
                        if (type == 1) d.deleteNode(val); else c.deleteNode(val);
                        break;
                case 6: cout << "Enter value: "; cin >> val;
                        if (type == 1) d.search(val); else c.search(val);
                        break;
                case 7: if (type == 1) d.display(); else c.display();
                        break;
            }
        }
    }
}
