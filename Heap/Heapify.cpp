#include <iostream>
using namespace std;

class Heap{
    public:  
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){  // TC: O(logn)
        size = size + 1;  //size++
        int idx = size;  //index of the new element
        arr[idx] = val;  //insert the element at the end

        while(idx > 1){
            int parent = idx / 2;   //parent index
            if(arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]); // if parent is smaller than child then swap
                idx = parent;   //  go to parent
            }
            else{
                return;
            }
        }
    }

    void deleteFromHeap(){   // TC: O(logn)
        //delete from means delete the root element
        if(size == 0) return;

        arr[1] = arr[size]; //replace the root element with the last element
        size--;

        // now maintain the heap property
        // check if the deleted element is smaller than its children
        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else return;
        }
    }

    void print(){
        for(int i = 1 ; i <= size ; i++){
            cout << arr[i] << " ";
        } 
        cout << endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    int arr[6] = {-1, 10, 20, 5, 6, 30};
    int n = 6;
    for(int i = n / 2; i > 0; i--){
        heapify(arr, n, i);
    }
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}