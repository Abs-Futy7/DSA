#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str) {
    stack<char> st;
    
    for(int i = 0; i < str.size(); i++) { 
        char ch = str[i]; // current char
        
        if(ch == '[' || ch == '{' || ch == '(') {
            st.push(ch); // push opening brackets onto the stack
        }
        else {
            // check if the stack is not empty and top matches the current closing bracket
            if(ch == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            }
            else if(ch == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }
            else if(ch == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                return false; 
            }
        }
    }

    return st.empty(); // return true if stack is empty, meaning all brackets matched
}

int main() {
    string str;
    cin >> str;
    cout << (isValid(str) ? "Valid" : "Invalid") << endl;
}
