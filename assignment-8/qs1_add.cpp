// Q1. Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no
// children. A left leaf is a leaf that is the left child of another node.
// Example:
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Link: Sum of Left Leaves - LeetCode

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

int sumOfLeftLeaves(Node* root, bool isLeft = false) {
    if (!root) return 0;
    if (!root->left && !root->right && isLeft) return root->val;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Sum of left leaves: " << sumOfLeftLeaves(root);
}
