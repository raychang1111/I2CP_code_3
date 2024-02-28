// https://www.luogu.com.cn/problem/P1106     刪數問題(經典貪心問題 目前未細看證明)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    string s;
    cin>>s>>t;
    vector<bool> s_enable(s.size(),true);
    for(int k=0;k<t;k++){
        int i=0;
        while(i<s.size()){
            if(s_enable[i]){
                int j=i+1;
                while(j<s.size() && !s_enable[j])
                    j++;
                if(s[i]>s[j]){
                    s_enable[i]=false;
                    break;
                }
            }
            i++;
        }
    }
    bool first=false;
    for(int i=0;i<s.size();i++){
        if(s_enable[i]){
            if(s[i]!='0')
                first=true;
            if(first)
                cout<<s[i];
        }
    }
    if(!first)
        cout<<0;
    cout<<'\n';
    return 0;
}
