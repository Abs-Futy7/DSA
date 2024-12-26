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


int diameterRecur(Node* root, int &ans) {
  
    if (root == nullptr)
        return 0;
    
    // find the height of left and right subtree
    // (it will also find of diameter for left 
    // and right subtree).
    int lHeight = diameterRecur(root->left, ans);
    int rHeight = diameterRecur(root->right, ans);
    
    // Check if diameter of root is greater than ans.
    ans = max(ans, lHeight+rHeight);
    
    // return the height of current subtree.
    return 1 + max(lHeight, rHeight);
}


int diameter(Node* root) {
  
    int ans = 0;
    
    diameterRecur(root, ans);
    
    return ans;
}

int main() {

    // Constructed binary tree is
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << diameter(root) << endl;

    return 0;
}