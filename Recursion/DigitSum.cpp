#include <iostream>
using namespace std;

int digitSum(int n){
    if(n<=9 && n>=0) return n; 
    return digitSum(n/10) + n%10;   
}

int main(){
    int n;
    cin >> n;
    int ans = digitSum(n);
    cout << ans << endl;
}