// Write a program to check if a doubly linked list of characters is palindrome or not.

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = tail = NULL;
    }

    void insertLast(char val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    bool isPalindrome() {
        Node* left = head;
        Node* right = tail;
        while (left && right && left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList d;
    string s = "LEVEL";
    for (char c : s) d.insertLast(c);

    if (d.isPalindrome())
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}
