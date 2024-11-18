#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &input, int k){
    int s = 0;
    int e = input.size() - 1;
    int ans = -1;
    while(s<=e){
        int mid = s + (e - s)/2;
        if(input[mid] == k){
            ans = mid;
            e = mid - 1;
        }
        else if(k > input[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << firstOccurence(v, k) << endl;
}