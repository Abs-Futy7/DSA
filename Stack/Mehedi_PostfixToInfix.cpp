
#include<bits/stdc++.h>
using namespace std;
void postfixtoinfix(string s)
{
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            
            int x = s[i] - '0';
            st.push(x);
            
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(s[i]=='+'){
                st.push(a+b);
            }
            else if(s[i]=='-'){
                st.push(a-b);
            }
            else if(s[i]=='*'){
                st.push(a*b);
            }
            else if(s[i]=='/'){
                st.push(a/b);
            }
        }
    }
    cout<<st.top();


}
int main()
{
    string s;
    cin>>s;
    postfixtoinfix(s);

    return 0;
}