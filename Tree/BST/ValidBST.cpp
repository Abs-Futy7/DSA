#include <iostream>
#include <climits> // Required for INT_MIN and INT_MAX
using namespace std;

class Node {
public:
    int data;       // Value of the current node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
 * Function: isBST
 * ------------------
 * This function checks whether a given binary tree is a valid Binary Search Tree (BST).
 * A valid BST must satisfy the following properties:
 * 1. For every node, its value must be between a specified "min" and "max" range.
 * 2. The left subtree of a node should contain values less than the node's value.
 * 3. The right subtree of a node should contain values greater than the node's value.
 *
 * Parameters:
 *  - root: Pointer to the current node in the tree.
 *  - min: The minimum allowable value for the current node (inclusive).
 *  - max: The maximum allowable value for the current node (inclusive).
 *
 * Returns:
 *  - true: If the tree rooted at "root" satisfies BST properties.
 *  - false: If the tree violates any BST property.
 */
bool isBST(Node* root, int min, int max) {
    // Base Case: If the current node is NULL, it's a valid BST
    if (root == NULL) return true;

    // Check if the current node's data lies in the allowable range [min, max]
    if (root->data >= min && root->data <= max) {
        /*
         * Recursively check the left and right subtrees:
         * - Left subtree: The max allowable value is updated to root->data.
         * - Right subtree: The min allowable value is updated to root->data.
         */
        bool left = isBST(root->left, min, root->data);   // Check left subtree
        bool right = isBST(root->right, root->data, max); // Check right subtree

        // Return true only if both left and right subtrees are valid BSTs
        return left && right;
    }
    else {
        // If current node violates the range condition, return false
        return false;
    }
}

int main() {
    Node* root = NULL;

    /*
     * Construct the following binary tree:
     *          5
     *        /   \
     *       3     6
     *      / \   / \
     *     2   4 5   7
     */
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(5);  
    root->right->right = new Node(7);

    // Check if the tree is a valid BST
    bool validate = isBST(root, INT_MIN, INT_MAX);

    // Print the result
    if (validate)
        cout << "Valid BST" << endl;
    else
        cout << "Not a valid BST" << endl;

    return 0;
}
