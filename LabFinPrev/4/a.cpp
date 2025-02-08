#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to perform in-order traversal and store values in a vector
void inOrderTraversal(TreeNode* root, vector<int>& values) {
    if (root == nullptr) return;
    inOrderTraversal(root->left, values);
    values.push_back(root->val);
    inOrderTraversal(root->right, values);
}

// a) Find the median of the values stored in the binary search tree
double findMedian(TreeNode* root) {
    vector<int> values;
    inOrderTraversal(root, values);
    int n = values.size();
    if (n % 2 == 1) {
        return values[n / 2];
    } else {
        return (values[(n / 2) - 1] + values[n / 2]) / 2.0;
    }
}


int main() {
    // Example usage
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    // a) Find the median
    cout << "Median: " << findMedian(root) << endl;

    return 0;
}
/*
✅ Time Complexity: O(n)
✅ Space Complexity: O(h) (recursive stack, h = height of tree) */