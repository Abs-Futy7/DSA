// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue <int, vector<int>, greater<int> > pq; 
        for(int i = 0 ; i < arr.size() ; i++){
            pq.push(arr[i]);
        }
        
        long long int cost = 0;
        while(pq.size() > 1){
            long long int a = pq.top();
            pq.pop();
            long long int b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            pq.push(sum);
        }
        
        return cost;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}