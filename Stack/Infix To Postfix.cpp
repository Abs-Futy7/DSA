#include <iostream>
#include <stack>
using namespace std;

int prec(char ch) {
    if (ch == '^') return 3;
    else if (ch == '/' || ch == '*') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return -1;
}

void infixToPostfix(string s) {
    stack<char> st;
    string result;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // if the scanned char is an operand, add to output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        // if the char is '(', push it to stack
        else if (c == '(') {
            st.push('(');
        }
        // if char is ')', pop and add to output string until '(' is found
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // pop '(' from stack
        }
        // if an operator is encountered
        else {
            while (!st.empty() && (prec(c) < prec(st.top()) || (prec(c) == prec(st.top()) && c != '^'))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main() {
    string str;
    cout << "Enter input: ";
    cin >> str;
    infixToPostfix(str);
    return 0;
}
