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

int height(Node* root){
    if(root == NULL) return -1;

    int left = height(root->left);
    int right = height(root->right);

    int ans =  max(left, right) + 1;

    return ans;
}

int main(){
    // Representation of the input tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << height(root);
}