// Given a linked list, and an integer k, rotate the list to the left by k positions and return
// the updated head.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }

    void print()
    {
        Node *temp = this;
        if (temp == NULL)
        {
            cout << "list is empty" << endl;
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node *rotateByK(Node *&head, int k)
{
    if (!head || k == 0)
        return head;

    Node *curr = head;
    int size = 0;
    while (curr)
    {
        size++;
        curr = curr->next;
    }

    k = k % size;
    if (k == 0)
        return head;

    // store the linked list in one array
    vector<int> arr;
    curr = head;
    while (curr)
    {
        arr.push_back(curr->data);
        curr = curr->next;
    }

    // rotate the array accordingly
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());

    // put them back in the list
    curr = head;
    int i = 0;
    while (curr)
    {
        curr->data = arr[i++];
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 9; i++)
    {
        temp->next = new Node(i);
        temp = temp->next;
    }

    rotateByK(head, 3);
    head->print();
}