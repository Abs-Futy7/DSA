#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int idx){
    if(idx >= n) return;

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    // Put maximum value at root and
    // recur for the child with the
    // maximum value
    if (largest != idx) {
        swap(arr[largest], arr[idx]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(vector<int> &arr, int n){
    for(int i = n/2 - 1 ; i >= 0 ; i--){
        maxHeapify(arr, n, i);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){
    vector<int> merged(n+m, 0);
    for(int i = 0 ; i < n ; i++){
        merged[i] = a[i];
    }
    for(int j = 0 ; j < m ; j++){
        merged[n+j] = b[j];
    }

    buildMaxHeap(merged, n+m);
    return merged;
}

int main(){
    vector<int> a = { 10, 5, 6, 2 };
    vector<int> b = { 12, 7, 9 };

    int n = a.size();
    int m = b.size();

    vector<int> merged = mergeHeaps(a, b, n, m);

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";

    return 0;
}