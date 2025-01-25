#include <iostream>
using namespace std;

void gen(int arr[], int pos, int n){
    if(pos == n){
        for(int i = 0 ; i < n ; i++){
            if(i == n-1){
                cout << arr[i];
            }
            else cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0 ; i <= 4 ; i++){
        if(i%2 == pos%2){
            arr[pos] = i;
            gen(arr, pos + 1 , n);
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    gen(arr, 0, n);
}