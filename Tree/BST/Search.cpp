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

bool search(Node* root, int x){
    if(root == NULL) return false;
    if(root->data == x) return true;

    if(root->data > x) return search(root->left, x);
    else return search(root->right, x);
}

int main(){
    Node* root = NULL;
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
    cout << search(root, 6) << endl;
}