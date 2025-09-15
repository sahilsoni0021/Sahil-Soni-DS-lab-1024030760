// Develop a menu driven program for the following operations on a Singly Linked
// List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values.

#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;  // or tail = tail -> next
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << endl;
        temp = temp -> next ;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* &head,int position,int d){

    // insert at start wala case 
    if (position == 1){
        insertAtHead(head,d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    // insert at last position
    if (temp -> next == NULL){
        insertAtTail(tail,d);
        return ;
    }

    // creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;

}

void deleteNode(int position , Node* &head){

    // deleting at first or start node
    if (position==1){
        Node* temp = head;
        head = head -> next;
        // memory free at start node
        temp -> next = NULL;
        delete temp;
    }

    else{
        // deleting any middle or start node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int choice;

    do {
        cout << "\n*** MENU ***" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete Node at Position" << endl;
        cout << "5. Print List" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        int data, position;

        switch(choice) {
            case 1:
                cout << "Enter data to insert at head: ";
                cin >> data;
                if (head == NULL) {
                    head = new Node(data);
                    tail = head;
                } else {
                    insertAtHead(head, data);
                }
                break;

            case 2:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                if (head == NULL) {
                    head = new Node(data);
                    tail = head;
                } else {
                    insertAtTail(tail, data);
                }
                break;

            case 3:
                cout << "Enter position to insert at: ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> data;
                if (head == NULL && position == 1) {
                    head = new Node(data);
                    tail = head;
                } else {
                    insertAtPosition(tail, head, position, data);
                }
                break;

            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteNode(position, head);
                break;

            case 5:
                print(head);
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while(choice != 6);

    return 0;
}