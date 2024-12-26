#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val > root->data) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int kthSmallest(Node* root, int& i, int k) {
    if (root == NULL) return -1;

    // Left subtree
    int left = kthSmallest(root->left, i, k);
    if (left != -1) return left;

    // Current node
    i++;
    if (i == k) return root->data;

    // Right subtree
    return kthSmallest(root->right, i, k);
}

int main() {
    Node* root = NULL;
    cout << "Enter elements of BST (-1 to stop): ";
    takeInput(root);

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int i = 0;
    int ans = kthSmallest(root, i, k);

    if (ans == -1) {
        cout << "The tree has fewer than " << k << " elements." << endl;
    } else {
        cout << "The " << k << "th smallest element is: " << ans << endl;
    }

    return 0;
}
