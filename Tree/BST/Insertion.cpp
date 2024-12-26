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

Node* insertIntoBST(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val > root->data){
        root->right = insertIntoBST(root->right, val);
    }
    else{
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}


void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

int main(){
    Node* root = NULL;
    takeInput(root);
    inorder(root);
}

