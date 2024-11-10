#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int k){
    if(size == 0) return false;
    if(arr[0] == k) return true;
    else{
        bool remainPart = linearSearch(arr+1, size-1, k);
        return remainPart;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int ans = linearSearch(arr, n, k);

    if(ans) cout << "Is present" << endl;
    else cout << "Nah" << endl;
}