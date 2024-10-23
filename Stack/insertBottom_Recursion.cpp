#include <iostream>
#include <stack>
using namespace std;

void insertAtBottomRecursion(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtBottomRecursion(st, x);
    st.push(curr);

}

// Time : O(n)
// Space : O(n)

int main(){
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(7);
    st.push(9);
    insertAtBottomRecursion(st, 5);
    while (!st.empty()) {
        int curr = st.top(); 
        st.pop();             
        cout << curr << " "; 
    }
}