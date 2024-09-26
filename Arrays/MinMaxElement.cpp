/*Don't put variable initializing an array in the main function
It is a bad practice.
Tou can put int arr[10000] it is still goood */

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  // min element
  int min = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  // max element
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  cout << " Min number is : " << min << endl;
  cout << " Max number is : " << max << endl;
}