// Given a binary tree, return its maximum depth. The depth of a binary tree is the number
// of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of
// the depths across all the paths.
// Example:
// Testing
// Input Format
// The first line contains an integer T denoting the number of test cases.
// For each test case, the input has 2 lines:
// The first line contains an integer n denoting the number of nodes in the tree (including the
// NULL nodes).
// The second line contains n space-separated integers that will form the binary tree. The
// integers follow level order traversal of the tree where -1 indicates a NULL node.
// Output Format
// For each test case, the output has an integer denoting the maximum depth of the tree.
// Sample Input
// 5
// 12
// 1 2 3 4 5 6 -1 -1 -1 7 -1 8
// 7
// 1 2 -1 4 -1 5 6
// 7
// 8 -1 9 -1 10 11 12
// 5
// 28 14 11 -1 48
// 1
// 6
// Expected Output
// 4
// 4
// 4
// 3
// 1
// Link: Maximum Depth of Binary Tree | Practice Problem
// Companies: Amazon, Facebook, Microsoft

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i >= arr.size()) break;
        if (arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Node* root = buildTree(arr);
        cout << maxDepth(root) << endl;
    }
}
