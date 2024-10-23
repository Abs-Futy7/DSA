#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st; // stores indexes of elements
    st.push(0); // push the first index

    for(int i = 1; i < n; i++) { // start from index 1
        // While stack is not empty and current element is greater than the top element of stack
        while(!st.empty() && arr[i] > arr[st.top()]) {
            output[st.top()] = arr[i]; // update the next greater element for the index at the top
            st.pop(); // pop the top element
        }
        st.push(i); // push the current index
    }
    
    // The remaining elements in the stack will have -1 as their next greater element
    return output;
}

int main() {
    int n;
    cin >> n; // input size of array
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i]; // input array elements
    }

    vector<int> res = nextGreaterElement(v); // call function to find next greater elements
    
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " "; // output the result
    }
    cout << endl;

    return 0;
}
