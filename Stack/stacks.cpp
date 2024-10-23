#include <iostream>
#include <climits>  // Include this to use INT_MIN
using namespace std;

class Stack {
    int capacity;
    int* arr;
    int top;

public:  
    Stack(int size) {
        this->capacity = size;
        arr = new int[size];
        this->top = -1;
    }

    void push(int data) {
        if(this->top == this->capacity - 1) {
            cout << "Overflow" << endl;
            return;  // No need to return a value as the function is void
        }

        this->top++;
        this->arr[this->top] = data;
    }

    int pop() {
        if(this->top == -1) {
            cout << "Underflow" << endl;
            return INT_MIN;  // Handle underflow by returning INT_MIN
        }
        int poppedValue = this->arr[this->top];
        this->top--;
        return poppedValue;
    }

    int getTop() {
        if(this->top == -1) {
            cout << "Underflow" << endl;
            return INT_MIN;  // Return INT_MIN if the stack is empty
        }
        return this->arr[this->top];
    }
    
    bool isEmpty() {
        return this->top == -1;
    }

    bool isFull() {
        return this->top == this->capacity - 1;
    }
};

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(5);
    st.push(7);

    cout << st.getTop() << endl;

    st.push(9);
    st.push(13);

    cout << st.getTop() << endl;

    return 0;
}

