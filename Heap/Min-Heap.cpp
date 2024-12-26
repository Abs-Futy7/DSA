#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is smaller than root
    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }

    // If right child is smaller than current smallest
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    // If smallest is not root
    if (smallest != i) {
        swap(arr[smallest], arr[i]);

        // Recursively heapify the affected subtree
        heapify(arr, n, smallest);
    }
}

int main() {
    int arr[6] = {10, 20, 5, 6, 30, 1}; // No dummy value, 0-based indexing
    int n = 6; // Size of the array

    // Build the min-heap
    for (int i = n / 2 - 1; i >= 0; i--) { // Start from the last non-leaf node
        heapify(arr, n, i);
    }

    // Print the min-heap
    for (int i = 0; i < n; i++) { // Print all elements
        cout << arr[i] << " ";
    }

    return 0;
}
