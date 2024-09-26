

#include <iostream>
using namespace std;

bool search(int arr[], int n, int key) {

  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, key;
  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter the key: ";
  cin >> key;

  bool found = search(arr, n, key);

  if (found) {
    cout << "Found";
  } else {
    cout << "Not Found";
  }
}