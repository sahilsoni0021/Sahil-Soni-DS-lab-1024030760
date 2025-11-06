// Given a 2D matrix, the task is to convert it into a doubly-linked list with four pointers
// that are next, previous, up, and down, each node of this list should be connected to its
// next, previous, up, and down nodes.
// https://www.geeksforgeeks.org/construct-a-doubly-linked-linked-list-from-2dmatrix/?ref=rp

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node* up;
    Node* down;
    Node(int val) {
        data = val;
        right = left = up = down = NULL;
    }
};

Node* construct(int mat[3][3], int n, int m) {
    Node* nodes[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            nodes[i][j] = new Node(mat[i][j]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m) nodes[i][j]->right = nodes[i][j + 1];
            if (j - 1 >= 0) nodes[i][j]->left = nodes[i][j - 1];
            if (i + 1 < n) nodes[i][j]->down = nodes[i + 1][j];
            if (i - 1 >= 0) nodes[i][j]->up = nodes[i - 1][j];
        }
    }

    return nodes[0][0];
}

void display(Node* head, int n, int m) {
    Node* row = head;
    while (row) {
        Node* col = row;
        while (col) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = construct(mat, 3, 3);
    display(head, 3, 3);
}
