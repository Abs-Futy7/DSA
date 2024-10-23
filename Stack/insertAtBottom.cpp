#include <iostream>
#include <stack>
using namespace std;

void insertAtBootm(stack<int> &st, int x){
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }

}

// Time : O(n)
// Space : O(n)

int main(){
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(7);
    st.push(9);
    insertAtBootm(st, 5);
    while (!st.empty()) {
        int curr = st.top(); 
        st.pop();             
        cout << curr << " "; 
    }
}
