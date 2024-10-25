#include <iostream>
#include <stack>
#include <cmath>  
using namespace std;

// Function to perform calculations based on the operator
int calc(int v1, int v2, char op) {
    if(op == '^') return (int)pow(v1, v2);  // Cast the result of pow to int
    if(op == '*') return v1 * v2;           // Multiplication
    if(op == '/') return v1 / v2;           // Division
    if(op == '+') return v1 + v2;           // Addition
    else return v1 - v2;                    // Subtraction
}

// Function to determine precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// Function to evaluate an infix expression
int eval(string &str) {
    stack<int> values;     // Stack for values (numbers)
    stack<char> operators; // Stack for operators

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // If the character is a digit, parse the full number
        if(isdigit(ch)) {
            values.push(ch - '0');
        }
        // If the character is an opening parenthesis
        else if(ch == '(') {
            operators.push(ch);
        }
        // If the character is a closing parenthesis
        else if(ch == ')') {
            while(!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                int v2 = values.top();
                values.pop();

                int v1 = values.top();
                values.pop();


                values.push(calc(v1, v2, op));
            }
            if(!operators.empty()) operators.pop();
        }
        // If the character is an operator
        else {
            // While the top of the operator stack has the same or greater precedence
            while(!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                char op = operators.top();
                operators.pop();

                int v2 = values.top();
                values.pop();

                int v1 = values.top();
                values.pop();


                values.push(calc(v1, v2, op));
            }
            operators.push(ch);
        }
    }

    // Entire expression has been parsed; apply remaining operators
    while(!operators.empty()) {
        char op = operators.top();
        operators.pop();

        int v2 = values.top();
        values.pop();

        int v1 = values.top();
        values.pop();


        values.push(calc(v1, v2, op));
    }

    // The result is the only value left in the stack
    return values.top();
}

int main() {
    string str;
    cout << "Enter an infix expression: ";
    cin >> str;
    cout << "Result: " << eval(str) << endl;
}
