#include <iostream>
using namespace std;

int main(){
    string s1;
    string s2 = "";
    cin >> s1;
    int freq[26] = {0};
    for(int i = 0; i < s1.size() ; i++){
        char ch = s1[i];
        int idx = ch - 'a';
        freq[idx]++;
    }

    for(int i = 0 ; i < 26 ; i++){
        char ch = 'a' + i;
        for(int j = 0 ; j < freq[i] ; j++){
            s2 += ch;
        }
    }

    cout << s2 << endl;
    
}