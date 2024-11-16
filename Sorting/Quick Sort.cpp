#include <iostream>
using namespace std;


int partition(int arr[], int first, int last){

    int pivot = arr[last];
    int i = first-1;  // inserting elements < pivot
    int j = first; // finding elements < pivot

    for( ; j < last ; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[last]);
    return i+1;
}




void quickSort(int arr[], int first, int last){
    if(first >= last) return;

    int pi = partition(arr, first, last);

    quickSort(arr, first, pi-1);
    quickSort(arr, pi+1, last);
}



int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}