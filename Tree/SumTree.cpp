// C++ program to check if Binary tree
// is sum tree or not
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x) {
            data = x;
            left = right = nullptr;
        }
};

// returns sum if tree is SumTree
// else return -1
int isSumTree(Node* root) {
    
    if(root == nullptr)
        return 0;
    
    // If node is leaf node, return its value.    
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    
    // Calculate left subtree sum
    int ls = isSumTree(root->left);
    
    // if left subtree is not sum tree,
    // return -1.
    if(ls == -1)
        return -1;
    
    // Calculate right subtree sum
    int rs = isSumTree(root->right);
    
    // if right subtree is not sum tree,
    // return -1.
    if(rs == -1)            
        return -1;
    
    
    if(ls + rs == root->data)
        return ls + rs + root->data;
    else
        return -1;
 
}

int main() {
    
    // create hard coded tree
    //       26
    //      /  \
    //     10   3
    //    / \    \
    //   4  6     3
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    
    if (isSumTree(root)!=-1)
        cout << "True";
    else
        cout << "False";

    return 0;
}