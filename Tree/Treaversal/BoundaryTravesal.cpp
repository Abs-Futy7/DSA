#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void traverseLeft(Node *root, vector<int> &ans) {
  // base case
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    return;

  ans.push_back(root->data);
  if (root->left)
    traverseLeft(root->left, ans);
  else
    traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans) {
  // base case
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL) {
    ans.push_back(root->data);
    return;
  }

  traverseLeaf(root->left, ans);
  traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans) {
  // base case
  if ((root == NULL) || (root->left == NULL && root->right == NULL))
    return;

  if (root->right)
    traverseRight(root->right, ans);
  else
    traverseRight(root->left, ans);

  // wapas aagye
  ans.push_back(root->data);
}

vector<int> boundary(Node *root) {
  vector<int> ans;
  if (root == NULL)
    return ans;

  ans.push_back(root->data);

  // left part print/store
  traverseLeft(root->left, ans);

  // traverse Leaf Nodes

  // left subtree
  traverseLeaf(root->left, ans);
  // right subtree
  traverseLeaf(root->right, ans);

  // traverse right part
  traverseRight(root->right, ans);

  return ans;
}

int main() {
  // Hardcoded Binary tree
  //        20
  //       /  \
    //      8    22
  //     / \     \
    //    4   12    25
  //       /  \
    //      10   14
  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(4);
  root->left->right = new Node(12);
  root->left->right->left = new Node(10);
  root->left->right->right = new Node(14);
  root->right->right = new Node(25);

  vector<int> ans = boundary(root);
  for (int x : ans) {
    cout << x << " ";
  }

  return 0;
}