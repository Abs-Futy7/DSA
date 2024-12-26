#include <iostream>
#include <vector>
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

void preorder(Node* root, vector<int> &arr, int &index){
    if(root == NULL) return;
    // copy the next element from the sorted array to the current node
    root->data = arr[index++];
    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}

void inorder(Node* root, vector<int> &arr){
    if(root == NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}


void BSTtoMinHeap(Node* root){
    
    vector<int> arr;

    // step 1 : do inorder traversal to get sorted array
    inorder(root, arr);

    int index = 0;

    // step 2 : do preorder traversal to convert the array to min heap
    preorder(root, arr, index);
}

void preorderPrint(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    BSTtoMinHeap(root);
    preorderPrint(root);
}




