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

Node* minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteBST(Node* root, int val){
    if(root == NULL) return root;
    if(root->data == val){

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteBST(root->right, mini);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteBST(root->right, val);
        return root;
    }
}

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
    int val;
    cout << "Enter the value to be deleted: ";
    cin >> val;
    deleteBST(root, val);
    inorder(root);
}