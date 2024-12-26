#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Perform heap sort
    int size = n; // Start with the full heap
    while (size > 1) {
        // Swap the root (max element) with the last element
        swap(arr[1], arr[size]);

        // Reduce the heap size
        size--;

        // Restore the heap property for the root
        heapify(arr, size, 1);
    }
}

int main(){
    int arr[6] = {-1, 10, 20, 5, 6, 30};
    int n = 5;
    HeapSort(arr, n);
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}