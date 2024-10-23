#include <iostream>
#include <stack>
using namespace std;

void removeAtBottom(stack<int> &st){
 
    stack<int> temp;

    // Move all elements from st to temp, except the bottom element
    while(st.size() != 0){
        int curr = st.top();  // Get the top element of st
        st.pop();             // Remove the top element from st
        temp.push(curr);      // Push the element to temp
    }

    // At this point, st is empty, and temp has the elements in reverse order.
    // The original bottom element of st has been removed.

    temp.pop(); // Pop the bottom element from temp, effectively removing it

    // Now, push the remaining elements from temp back to st to restore the stack
    while(!temp.empty()){
        int curr = temp.top();  // Get the top element of temp
        temp.pop();             // Remove the top element from temp
        st.push(curr);          // Push it back to the original stack st
    }
}

int main(){

    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(7);
    st.push(9);

    removeAtBottom(st);

    while (!st.empty()) {
        int curr = st.top(); 
        st.pop();           
        cout << curr << " "; 
    }

    return 0;
}
