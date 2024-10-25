#include <iostream>
#include <stack>
#include <cmath>  
using namespace std;

// Function to perform the calculation based on the operator
int calc(int v1, int v2, char op){
    if(op == '^') return (int)pow(v1, v2);  // Cast the result of pow to int
    if(op == '*') return v1 * v2;           // Multiplication
    if(op == '/') return v1 / v2;           // Division
    if(op == '+') return v1 + v2;           // Addition
    else return v1 - v2;                    // Subtraction
}

// Function to evaluate a postfix expression
int eval(string &str){
    stack<int> st;  // Stack to store operands
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(isdigit(ch)){  // If it's a digit, push it onto the stack
            st.push(ch - '0');  // Convert char to int by subtracting '0'
        }
        else{  // If it's an operator
            int v2 = st.top();  // Get the second operand
            st.pop();
            int v1 = st.top();  // Get the first operand
            st.pop();
            // Perform the calculation and push the result back onto the stack
            st.push(calc(v1, v2, ch));
        }
    }
    return st.top();  // The result is the only value left in the stack
}

int main(){
    string str;  // Input string containing the postfix expression
    cin >> str;  // Take input from the user
    cout << eval(str) << endl;  // Evaluate and print the result
}
