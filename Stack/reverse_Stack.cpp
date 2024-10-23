#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &st){
    stack<int> t1, t2;
    
    // Transfer all elements from st to t1
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }

    // Transfer all elements from t1 to t2 (this reverses the order)
    while(!t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }

    // Transfer all elements from t2 back to st
    while(!t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}

int main(){
    stack<int> st;
    st.push(4);
    st.push(5);
    st.push(7);
    st.push(9);

    cout << "Original Stack: ";
    stack<int> temp = st; // Use a temporary stack to print without modifying the original
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        cout << curr << " ";
    }
    cout << endl;

    // Reverse the stack
    reverseStack(st);

    cout << "Reversed Stack: ";
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout << curr << " ";
    }
    cout << endl;

    return 0;
}
