// https://www.luogu.com.cn/problem/P1241
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    vector<bool> mate(s.size(),false);
    for(int i=0;i<s.size();i++){
        if(s[i]==']' || s[i]==')'){
            int j;
            for(j=i-1;j>=0;j--){
                if(mate[j])
                    continue;
                if(s[j]=='[' || s[j]=='('){
                    if(s[i]==']' && s[j]=='['){
                        // cout<<i<<j<<endl;
                        mate[i]=true;
                        mate[j]=true;
                    }
                    if(s[i]==')' && s[j]=='('){
                        // cout<<i<<j<<endl;
                        mate[i]=true;
                        mate[j]=true;
                    }
                    break;
                }
            }
        }
    }
    for(int i=0;i<s.size();i++){
        if(mate[i]){
            cout<<s[i];
        }
        else{
            if(s[i]=='(' || s[i]==')')
                cout<<"()";
            if(s[i]=='[' || s[i]==']')
                cout<<"[]";
        }
    }
    cout<<'\n';
    return 0;
}