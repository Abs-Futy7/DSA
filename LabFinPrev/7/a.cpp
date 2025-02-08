#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root, vector<int>& v) {
    if (root == nullptr) return;
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

Node* buildBST(vector<int>& v, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* root = new Node(v[mid]);
    root->left = buildBST(v, start, mid - 1);
    root->right = buildBST(v, mid + 1, end);
    return root;
}

Node* mergeTrees(Node* root1, Node* root2) {
    vector<int> v1, v2;
    inorderTraversal(root1, v1);
    inorderTraversal(root2, v2);
    
    vector<int> merged;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) merged.push_back(v1[i++]);
        else merged.push_back(v2[j++]);
    }
    while (i < v1.size()) merged.push_back(v1[i++]);
    while (j < v2.size()) merged.push_back(v2[j++]);
    
    return buildBST(merged, 0, merged.size() - 1);
}

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    // Example usage
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Node* mergedRoot = mergeTrees(root1, root2);
    printInorder(mergedRoot);
    return 0;

}