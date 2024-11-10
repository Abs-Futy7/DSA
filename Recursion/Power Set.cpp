#include <iostream>
using namespace std;

void powerSet(string input, string output, int idx){
    if(idx == input.length()){
        cout << "{" << output << "} ";
        return;
    }
    powerSet(input, output, idx+1); // excluding
    powerSet(input, output + input[idx], idx+1); //include

}

int main(){
    string str;
    cin >> str;
    powerSet(str, "", 0);
}