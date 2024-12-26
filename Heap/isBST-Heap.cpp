#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isCBT(Node* root, int index, int totalCount){
    if(root == NULL) return true;
    if(index >= totalCount) return false;    // check if the index is greater than the total number of nodes

    // if the index is equal to the total number of nodes then it is a complete binary tree
    else{
        bool left = isCBT(root->left, 2*index + 1, totalCount);  // check if the left child is a complete binary tree
        bool right = isCBT(root->right, 2*index + 2, totalCount);  // check if the right child is a complete binary tree
        return (left && right);
    }
}

bool isMaxOrder(Node* root){
    if(root->left == NULL && root->right == NULL) return true;    // if the root has no children then it is a max heap
    if(root->right == NULL){     // if the root has only left child
        return (root->data > root->left->data);
    }
    else{        // if the root has both left and right children
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return(left && right &&
        (root->data > root->left->data) &&   // check if the root is greater than its left and right child
        (root->data > root->right->data));
    }
}

int countNodes(Node* root){
    if(root == NULL) return 0;
    int ans = 1 + countNodes(root->left) + countNodes(root->right);  // count the number of nodes
    return ans;
}

bool isHeap(Node* root){
    int index = 0;
    int totalCount = countNodes(root);
    if(isCBT(root, index, totalCount) && isMaxOrder(root)){   // check if the tree is a complete binary tree and a max heap
        return true;
    }
    else{
        return false;
    }
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    if (isHeap(root)) {
        cout << "The binary tree is a heap." << endl;
    } else {
        cout << "The binary tree is not a heap." << endl;
    }

    return 0;
}