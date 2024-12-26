#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        // Push the current element onto the max heap
        pq.push(arr[i]);

        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }

    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}


int main()
{
    int N = 10;
    int arr[N] = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
    int K = 4;

    // Function call
    cout << "Kth Smallest Element is: "
         << kthSmallest(arr, N, K);
}