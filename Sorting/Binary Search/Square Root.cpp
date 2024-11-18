#include <iostream>
using namespace std;

int sqrt(int x){
    int s = 0;
    int e = x;
    int ans = -1;

    while(s<=e){
        int mid = s + (e - s)/2;

        if(mid*mid <= x){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << "square root is : " << sqrt(n) << endl;
}