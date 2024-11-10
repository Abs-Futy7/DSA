#include <iostream>
using namespace std;

void printArray(int *arr, int idx, int n){
    if(idx == n) return;
    cout << arr[idx] << endl;
    printArray(arr, idx+1, n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    printArray(arr, 0, n);
}