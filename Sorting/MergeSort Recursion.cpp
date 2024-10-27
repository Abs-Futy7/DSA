#include <iostream>
using namespace std;

void merge(int arr[], int str, int mid, int end){
    int an = mid - str + 1;
    int bn = end - mid;

    int a[an], b[bn];

    for(int i = 0 ; i < an ; i++){
        a[i] = arr[str + i];
    }

    for(int j = 0 ; j < bn ; j++){
        b[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = str;

    while(i < an && j < bn){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i < an){
        arr[k++] = a[i++];
    }
    while(j < bn){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[], int str, int end){
    if(str >= end){
        return;
    }

    int mid = (str + end) / 2;

    mergeSort(arr, str, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, str, mid, end);
}

int main(){
    int arr[] = {1, 6, 99, 23, 65, -1};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
