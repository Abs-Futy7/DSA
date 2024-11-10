#include <bits/stdc++.h>
using namespace std;


void permuteRec(string& s, int idx)  {
    // Base case
    if (idx == s.size() - 1) {
        cout << s << " ";
        return;
    }

    for (int i = idx; i < s.size(); i++) {
      
        // Swapping
        swap(s[idx], s[i]);

        // Recurse with the next character fixed
        permuteRec(s, idx + 1);

        // Backtrack
        swap(s[idx], s[i]);
    }
}

int main(){
    string str;
    cin >> str;
    permuteRec(str, 0);  
    return 0;
}
