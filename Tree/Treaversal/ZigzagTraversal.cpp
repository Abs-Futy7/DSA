#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public :  
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> zigzagTraversal(Node* root) {
    // Result vector to store the final zigzag order traversal.
    vector<int> result;
    
    // If the root is NULL, return an empty result.
    if (root == NULL) 
        return result;

    // Queue for level order traversal.
    queue<Node*> q;
    q.push(root); // Start with the root node.

    // Boolean to track the current direction of traversal.
    // `true` means left-to-right, `false` means right-to-left.
    bool leftToRight = true;

    // Continue until the queue is empty (all levels processed).
    while (!q.empty()) {
        int size = q.size(); // Number of nodes at the current level.
        
        // Temporary vector to store the current level's values.
        // Size is preallocated to avoid resizing during the loop.
        vector<int> ans(size);

        // Process all nodes at the current level.
        for (int i = 0; i < size; i++) {
            // Get the front node in the queue.
            Node* frontNode = q.front();
            q.pop(); // Remove it from the queue.

            // Determine the index in `ans` based on the direction of traversal.
            int idx = leftToRight ? i : size - i - 1;
            ans[idx] = frontNode->data; // Place the data in the correct position.

            // Add the left child to the queue if it exists.
            if (frontNode->left) 
                q.push(frontNode->left);

            // Add the right child to the queue if it exists.
            if (frontNode->right) 
                q.push(frontNode->right);
        }

        // Flip the direction for the next level.
        leftToRight = !leftToRight;

        // Append the current level's values to the result vector.
        // This ensures all levels are processed in order.
        for (int i = 0; i < ans.size(); i++) {
            result.push_back(ans[i]);
        }
    }

    // Return the final result containing zigzag order traversal.
    return result;
}



void printList(vector<int> v) {
    int n = v.size();
    for (int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \     \
    //   4   12    11
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    vector<int> ans = zigzagTraversal(root);
    printList(ans);
}