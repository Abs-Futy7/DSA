#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> &input) {
    stack<int> temp;

    // Copy contents from input stack to temp stack
    while (!input.empty()) {
        int curr = input.top();  // Get the top element of input stack
        input.pop();             // Remove the top element from input stack
        temp.push(curr);         // Push current element to temp stack
    }

    stack<int> result;

    // Copy contents from temp stack to result stack (to reverse the order)
    while (!temp.empty()) {
        int curr = temp.top();  // Get the top element of temp stack
        temp.pop();             // Remove the top element from temp stack
        result.push(curr);      // Push current element to result stack
    }

    return result; 
}

int main() {
    stack<int> st;
    st.push(4);
    st.push(5);
    st.push(-1);

    stack<int> res = copyStack(st); 

    // Print the elements of the copied stack
    while (!res.empty()) {
        int curr = res.top(); 
        res.pop();             
        cout << curr << endl; 
    }
}
