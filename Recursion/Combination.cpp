#include <iostream>
using namespace std;

void combinations(string input, string output, int n) {
    // Base condition: if the output has reached the desired length, print it
    if (output.length() == n) {
        cout << output << endl;
        return;
    }

    // Recursive case: try adding each character from the input string
    for (int i = 0; i < input.length(); i++) {
        combinations(input, output + input[i], n);
    }
}

int main() {
    string str;
    cin >> str;
    int length = str.length();  // Length of each combination
    cout << "All combinations of length " << length << " are:\n";
    combinations(str, "", length);
    return 0;
}
