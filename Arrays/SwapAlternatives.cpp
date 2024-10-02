#include <iostream>
using namespace std;

void swapAlternate(int arr[], int n){
    for(int i = 0 ; i<n-1 ; i+=2){
        swap(arr[i], arr[i+1]);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    for(int i = 0 ; i<n ; i++){
        cin>> arr[i] ;
    }

    swapAlternate(arr, n);

    for(int i = 0 ; i<n ; i++){
        cout<< arr[i] << " ";
    }
}