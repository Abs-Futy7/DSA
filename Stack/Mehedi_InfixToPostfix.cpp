//AB*C+D  ------> ABCD+*


#include<bits/stdc++.h>
using namespace std;
void infixtopostfix(string s)
{
    queue<char> q;
    stack<char> op;
    string result;
    
    int i=0;
    while(i<s.length()){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
             q.push(s[i]);
        }
        else{
            op.push(s[i]);
        }
        i++;
    }
    while(!q.empty()){
        result+=q.front();
        q.pop();
    }
    while(!op.empty()){
        result+=op.top();
        op.pop();
    }

    cout<<result;
    

}
int main()
{
    string s;
    cin>>s;
    infixtopostfix(s);
    return 0;
}