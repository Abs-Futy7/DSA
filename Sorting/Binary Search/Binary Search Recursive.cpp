#include <iostream>
using namespace std;

bool binarySearchRecursion(int arr[], int s, int e, int k){
    while(s <= e){
        int mid = s + (e - s) / 2;

        if(arr[mid] == k) 
            return true;
        else if(k > arr[mid]) 
           return binarySearchRecursion(arr, mid + 1, e, k);
        else 
            return binarySearchRecursion(arr, s, mid - 1, k);
    }
    return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool ans = binarySearchRecursion(arr, 0, n - 1, k);

    if(ans) 
        cout << "Present" << endl;
    else 
        cout << "Not present" << endl;

    return 0;
}