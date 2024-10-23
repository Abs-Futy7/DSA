#include <iostream>
#include <stack>
using namespace std;

void f(stack<int> &st, stack<int> &res){
    // Base case: if the input stack st is empty, return
    if(st.empty()) return;

    // Recursive step:
    // 1. Remove the top element from stack st
    int curr = st.top();
    st.pop();

    // 2. Recursively call f to reverse the remaining elements of st
    f(st, res);

    // 3. After recursion unwinds, push the current element to stack res
    res.push(curr);
}

int main() {
    stack<int> st;
    st.push(4);
    st.push(5);
    st.push(-1);

    stack<int> res;
    f(st, res);

    while (!res.empty()) {
        int curr = res.top();
        res.pop();
        cout << curr << endl;
    }

    return 0;
}
