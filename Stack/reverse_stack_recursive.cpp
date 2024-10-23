#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert element at the bottom of the stack
void insertAtBottom(stack<int> &st, int elem) {
    if(st.empty()) {
        st.push(elem);
        return;
    }
    
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, elem);  // Recursive call to insert element at bottom
    st.push(topElem);          // Restore the top element after inserting at the bottom
}

// Function to reverse the stack recursively
void reverseStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    
    int topElem = st.top();
    st.pop();
    reverseStack(st);          // Recursively reverse the remaining stack
    insertAtBottom(st, topElem); // Insert the popped element at the bottom
}

int main() {
    stack<int> st;
    st.push(4);
    st.push(5);
    st.push(7);
    st.push(9);

    cout << "Original Stack: ";
    stack<int> temp = st; // Use a temporary stack to print without modifying the original
    while(!temp.empty()) {
        int curr = temp.top();
        temp.pop();
        cout << curr << " ";
    }
    cout << endl;

    // Reverse the stack
    reverseStack(st);

    cout << "Reversed Stack: ";
    while(!st.empty()) {
        int curr = st.top();
        st.pop();
        cout << curr << " ";
    }
    cout << endl;

    return 0;
}
