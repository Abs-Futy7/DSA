// c) Build a new tree where left nodes have
// higher values and right nodes have lower values

#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildInvertedTree(Node* root){
    if(root == NULL) return NULL;

    Node* newTree = new Node(root->data);
    newTree->left = buildInvertedTree(root->right);
    newTree->right = buildInvertedTree(root->left);

    return newTree;

}

void printTree(Node* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}


int main() {
    // Example usage
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node* invertedRoot = buildInvertedTree(root);
    cout << "Inverted tree (in-order): ";
    printTree(invertedRoot);
    cout << endl;

}