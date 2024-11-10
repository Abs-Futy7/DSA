#include <iostream>
using namespace std;

int powerRec(int n, int b){
    if(b == 0) return 1; 
    return n * powerRec(n, b-1); 
}

int main(){
    int n, b;
    cin >> n >> b;
    int ans = powerRec(n, b);
    cout << ans << endl;
}