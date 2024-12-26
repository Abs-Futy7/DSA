#include <iostream>
#include <queue>
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

Node* createTree(Node* root){
    cout << "Enter data" << endl;
    int data;
    cin>> data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout <<"Enter data for inserting in left of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = createTree(root->right);

    return root;
};


void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // Ans: 4 2 5 1 6 3 7

    Node* root = NULL;
    root = createTree(root);

    inorder(root);
}