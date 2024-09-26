/* Array values are passed by reference
So when we pass the array to the function, the changes will be reflected in the
main function*/

#include <iostream>
using namespace std;

void update(int arr[], int main) {
  cout << endl << "Inside the function" << endl;

  // update the array
  arr[0] = 100;

  // printing the array
  for (int i = 0; i < 3; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << "Going back to the main function" << endl;
}

int main() {
  int arr[3] = {1, 2, 3};

  update(arr, 3);

  cout << "Printing the main function" << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr[i] << " ";
  }
}