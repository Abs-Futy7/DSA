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

bool isIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL && r2 != NULL) return false;
    if(r1 != NULL && r2 == NULL) return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value) return true;
    else return false;
}

int main(){
    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    Node* r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);
    r1->left->left = new Node(4);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    Node* r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    r2->left->left = new Node(4);

    if (isIdentical(r1, r2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}