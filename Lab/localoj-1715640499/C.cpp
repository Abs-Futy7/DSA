#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> m;
    int queries[m];
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }

    // For each query, find the number of elements less than or equal to it
    for (int i = 0; i < m; ++i) {
        int query = queries[i];
        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= query) {
                // If the middle element is <= query, all elements to the left are also <= query
                result = mid + 1; // Update result
                left = mid + 1;   // Search in the right half
            } else {
                // If the middle element is > query, search in the left half
                right = mid - 1;
            }
        }

        cout << result << "\n";
    }

    return 0;
}