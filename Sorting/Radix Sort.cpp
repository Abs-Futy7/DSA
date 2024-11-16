#include <iostream>
using namespace std;

// A function to perform counting sort on arr[] based on the digit represented by pos
void countSort(int arr[], int n, int pos)
{
    int output[n];          // Output array to store sorted elements based on current digit
    int count[10] = { 0 };   // Initialize count array for each digit (0-9)

    // Count occurrences of each digit in the given position (pos)
    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;  // Isolate the digit at position `pos` and increment count

    // Update count[i] to contain the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];  // Cumulative count helps determine final position in output array

    // Build the output array by placing elements at the correct position based on the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;  // Decrease count for the used digit
    }

    // Copy sorted elements from output[] back to arr[] for this digit position
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to sort arr[] of size n using Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number in arr[] to determine the number of digits
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];  // Update maximum if a larger number is found
    }

    // Apply counting sort to each digit place (units, tens, hundreds, etc.)
    // pos represents the digit position (1, 10, 100, etc.)
    for (int pos = 1; mx / pos > 0; pos *= 10)
        countSort(arr, n, pos);  // Call counting sort for the current digit position
}

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);  // Sort the array using Radix Sort
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

