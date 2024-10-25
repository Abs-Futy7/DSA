
/*      Push Efficient       */


#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> st;
    public:  
    Queue() {}

    void push(int x){
        this->st.push(x);  // TC: O(1)
    }  /// queue.enqeue

    void pop(){   // TC: O(n)
        if(this->st.empty()) return;

        stack<int> temp;
        while(this->st.size()>1){
            temp.push(st.top());
            st.pop();
        }
        //now stack size is 1, we are at the bottom
        this->st.pop();
        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }

    }

    bool empty(){
        return this->st.empty();
    }

    int front(){
        if(this->st.empty()) return -1;

        stack<int> temp;
        while(this->st.size()>1){
            temp.push(st.top());
            st.pop();
        }
        //now stack size is 1, we are at the bottom
        int result = this->st.top();
        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }
        return result;
    }


};

int main(){
    Queue qu;
    qu.push(10);
    qu.push(30);
    qu.push(60);
    qu.push(80);
    qu.push(50);
    qu.pop();

    while(!qu.empty()){
        cout << qu.front() << " ";
        qu.pop(); 
    }

}