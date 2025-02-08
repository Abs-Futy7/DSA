// b) Traverse a binary search tree in descending order

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

void traverseDescending(Node* root){
    if(root == NULL) return;

    traverseDescending(root->right);
    cout << root->data << " ";
    traverseDescending(root->left);
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

    cout << "Descending order: ";
    traverseDescending(root);
    cout << endl;

}