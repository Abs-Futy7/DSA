#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int id[n];
    int marks[n];
    for (int i = 0; i < n; i++) {
        cin >> id[i] >> marks[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1] || (marks[j] == marks[j + 1] && id[j] > id[j + 1])) {
                swap(marks[j], marks[j + 1]);
                swap(id[j], id[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << id[i] << endl;
    }

    return 0;
}
