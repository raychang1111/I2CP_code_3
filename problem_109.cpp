// https://www.luogu.com.cn/problem/P1143
#include <bits/stdc++.h>
using namespace std;
int T(int n,string &s){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9')
            ans=ans*n+s[i]-'0';
        else
            ans=ans*n+(s[i]-'A'+10);
    }
    return ans;
}
void IT(int m,int x){
    if(x){
        IT(m,x/m);
        if(x%m<10)
            cout<<x%m;
        else
            cout<<(char)('A'+x%m-10);
    }
}
int main(){
    int n,m;
    string s;
    cin>>n;
    cin>>s;
    cin>>m;
    // cout<<T(n,s)<<' ';
    IT(m,T(n,s));
    return 0;
}