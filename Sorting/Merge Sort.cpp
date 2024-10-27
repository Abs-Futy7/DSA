#include <iostream>
using namespace std;

void merge_Array(int arr1[], int n, int arr2[], int m, int arr3[]){
    int i = 0, j = 0, k = 0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }

    }
    //Copying first array
    while(i<n){
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    // Copying second array elments
    while(j<m){
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

void print_Array(int arr3[], int k){
    for(int i=0;i<k;i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr1[5] = {1, 3, 5, 9, 12};  // Array need to be sorted
    int arr2[3] = {7, 8, 10};

    int arr3[5+3] = {0};

    merge_Array(arr1, 5, arr2, 3, arr3);

    print_Array(arr3, 8);

    return 0;
}