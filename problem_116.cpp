// https://www.luogu.com.cn/problem/P3375 (KMP¼ÒªO)
#include<bits/stdc++.h>
using namespace std;
void init_border(string t,vector<int> &border){
    for(int i=1,j=-1;i<t.size();i++){
        while(0<=j && t[i]!=t[j+1]){
            j=border[j];
        }
        if(t[i]==t[j+1])
            j++;
        border[i]=j;
    }
}
int main(){
    string s,t;
    cin>>s>>t;
    vector<int> border(t.size(),-1);
    init_border(t,border);
    for(int i=0,j=-1;i<s.size();i++){
        while(0<=j && s[i]!=t[j+1]){
            j=border[j];
        }
        if(s[i]==t[j+1])
            j++; 
        if(j+1==t.size()){
            cout<<i+1-t.size()+1<<'\n';
            j=border[j];
        }
    }
    for(int i=0;i<border.size();i++)
        cout<<border[i]+1<<' ';

    cout<<'\n';
    return 0;
}