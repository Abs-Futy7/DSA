#include <iostream>
using namespace std;

int printMax(int *arr, int idx, int n){
    if(idx == n-1) return arr[idx];
    return max(arr[idx], printMax(arr, idx+1, n));
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int maxim = printMax(arr, 0, n);
    cout << maxim << endl;
}