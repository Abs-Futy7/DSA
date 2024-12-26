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


void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


void inorder(Node* root, int &cnt) {
    if(root == NULL) return;
    inorder(root->left, cnt);
    if(root->left == NULL && root->right == NULL) {
        cnt++;
    }
    inorder(root->right, cnt);
}

int main(){
    Node* root = NULL;
    root = createTree(root);
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    int cnt = 0;
    inorder(root, cnt);
    cout << "Leaf nodes are: " << cnt << endl;

    return 0;
}