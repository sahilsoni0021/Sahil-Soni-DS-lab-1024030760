// Given a linked list, remove the loop if it exists.

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int x)  {
        data = x;
        next = NULL;
    }

    void print(){
        Node* temp = this;
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
};

void removeLoop(Node* head){

    if (head == NULL || head -> next == NULL){
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // firsly check if the loop is present or not
    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast){
            break;
        }
    }

    if (!fast || !fast -> next){
        return ;
    }

    // if loop start from head
    if (slow == head){
        while(fast -> next != head){
            fast = fast -> next;
        }
        fast ->  next = NULL;
        return;
    }

    // find the start of the loop
    slow = head;
    while(slow -> next != fast -> next){
        slow = slow -> next;
        fast = fast -> next;
    }

    fast -> next = NULL; // remove loop
}


int main(){
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 9; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    temp -> next = head -> next -> next; // loop exist now where 9 will have the next pointer pointed to 3
    removeLoop(head);

    cout << "loop is removed now" << endl;
    head->print();
}   