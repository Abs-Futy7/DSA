#include <bits/stdc++.h>

using namespace std;

void tripleRecursion(int n, int m, int k) {
    // Complete this function
    int arr[n][n];
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            if(i == 0 && j == 0) arr[i][j] = m;
            else if(i == j) arr[i][j] = arr[i-1][j-1] + k;
            else if(i > j) arr[i][j] = arr[i-1][j] - 1;
            else arr[i][j] = arr[i][j-1] - 1;
        }
    }
    
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    tripleRecursion(n, m, k);
    return 0;
}