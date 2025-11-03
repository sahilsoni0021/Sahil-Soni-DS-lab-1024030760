// Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining
// nodes after multiples of k should be left as it is.

// Input: Linked list: 1→2→3→4→5→6→7→8→9 ,K: 3
// Output: Result: 3→2→1→6→5→4→9→8→7

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

Node* reverseKGroup(Node* head, int k){
    Node* curr = head; 
    int count = 0;

    while(curr && count < k){
        curr = curr -> next;
        count ++;
    }

    if (count < k){
        return head;
    }

    Node* prev = NULL;
    curr = head;
    Node* next = NULL;
    count = 0;
    while(curr && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next){
        head -> next = reverseKGroup(next,k);
    }
    return prev;
}

int main(){
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 9; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    int k = 3;
    head = reverseKGroup(head,k);
    head->print();
}   