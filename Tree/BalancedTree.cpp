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
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

bool isBalanced(Node* root){
    if(root == NULL) return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    bool diff = abs(lh-rh) <= 1;

    if(diff && isBalanced(root->left)  && isBalanced(root->right)){
        return 1;
    }

    return 0;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}