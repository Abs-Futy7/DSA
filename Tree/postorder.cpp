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


void postorder(Node* root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){

    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    // Ans: 4 5 2 6 7 3 1

    Node* root = NULL;
    root = createTree(root);

    postorder(root);
}