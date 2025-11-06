// Given an integer n, return all the structurally unique BST's (binary search trees), which
// has exactly n nodes of unique values from 1 to n. Return the answer in any order.
// Example 1:
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:
// Input: n = 1
// Output: [[1]]
// Constraints:
// 1 <= n <= 8
// Link: 95. Unique Binary Search Trees II - Medium | DSA Corner | Talentd
// Companies: Microsoft, Adobe, Bloomberg, Uber

#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

vector<TreeNode*> generate(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = generate(start, i - 1);
        vector<TreeNode*> rightTrees = generate(i + 1, end);
        for (auto l : leftTrees) {
            for (auto r : rightTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generate(1, n);
}

void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> result = generateTrees(n);

    cout << "Total Unique BSTs: " << result.size() << endl;
    cout << "Preorder traversal of each BST:" << endl;
    for (auto root : result) {
        preorder(root);
        cout << endl;
    }
}
