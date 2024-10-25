#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> qu;
    qu.push(22);
    qu.push(24);
    qu.push(27);
    qu.push(29);

    while(!qu.empty()){
        cout<< qu.front() << " ";
        qu.pop();
    }
}