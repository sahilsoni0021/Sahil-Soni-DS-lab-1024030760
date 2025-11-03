// write a program to reverse a linked list
// input : 1 2 3 4 NULL;
// output : 4 3 2 1 NULL;


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    Node* head;

    public:
    LinkedList(){
        head = NULL;
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print(){
        Node* temp = head;
        if (temp == NULL){
            cout << "list is empty" << endl;
            return ;
        }

        while(temp != NULL){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    Node* reverseList(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};


int main(){
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);


    cout << "original list " ;
    list.print();
    cout << endl;
    cout << "after reversing " ;
    list.reverseList();
    list.print();
}