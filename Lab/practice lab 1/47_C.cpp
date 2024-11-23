#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Queue{
    vector<int> st1, st2;
    
    public:
    void enqueue(int x){
        st1.push_back(x);
    }
    
    void dequeue(){
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push_back(st1.back());
                st1.pop_back();
            }
        }
        if (!st2.empty()) {
            st2.pop_back();
        }
    }
    
    int front(){
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push_back(st1.back());
                st1.pop_back();
            }
        }
        return st2.back();
    }
    
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    Queue qu; 
    int n, x, y;
    cin >> n;
    while(n--){
        cin >> x;
        if(x==1){
            cin >> y;
            qu.enqueue(y);
        } 
        else if(x==2){
            qu.dequeue();
        }
        else{
            cout << qu.front() << endl;
        }
    }
    return 0;
}