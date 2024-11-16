#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

void bucketSort(float arr[], int size) {
    // Step 1: Create buckets
    vector<vector<float>> bucket(size, vector<float>());

    // Finding range for scaling
    float mx = arr[0];
    float mn = arr[0];

    for (int i = 1; i < size; i++) {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    float range = (mx - mn) / size;

    // Step 2: Insert elements into buckets
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - mn) / range;
        if (index == size) index = size - 1; // Fix for edge case where index equals size
        bucket[index].push_back(arr[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < size; i++) {
        if (!bucket[i].empty()) {
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    // Step 4: Combine elements from buckets back into arr
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (size_t j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    float arr[] = {0.2, 0.45, 1.34, 0.78, 0.12, 0.23};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
