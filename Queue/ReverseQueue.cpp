#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    queue<int> qu;
    qu.push(22);
    qu.push(24);
    qu.push(27);
    qu.push(29);

    stack<int> st;
    while(!qu.empty()){
        st.push(qu.front());
        qu.pop();
    }

    while(!st.empty()){
        qu.push(st.top());
        st.pop();
    }
    
    while(!qu.empty()){
        cout<< qu.front() << " ";
        qu.pop();
    }
}