#include <iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int k){
    while(s <= e){
        int mid = s + (e - s) / 2;

        if(arr[mid] == k) 
            return mid;
        else if(k > arr[mid]) 
            s = mid + 1;
        else 
            e = mid - 1;
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

    bool ans = binarySearch(arr, 0, n - 1, k);

    if(ans) 
        cout << "Present" << endl;
    else 
        cout << "Not present" << endl;

    return 0;
}
