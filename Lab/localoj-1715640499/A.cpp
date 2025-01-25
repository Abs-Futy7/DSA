#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        frequency[num]++;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int query;
        cin >> query;
        cout << frequency[query] << endl;
    }

    return 0;
}
