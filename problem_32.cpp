// https://www.luogu.com.cn/problem/P2437
#include <bits/stdc++.h>
#define int long long
using namespace std;
class MAX_NUMBER{
public:
    string s;
    MAX_NUMBER(){
        s="0";
    }
    MAX_NUMBER(string a){
        s=a;
    }
    MAX_NUMBER operator+(MAX_NUMBER &a){
        int temp;
        bool carry=false;
        string res;
        for(int i=0;i<max(s.size(),a.s.size());i++){
            temp=0;
            if(i<s.size())
                temp+=(s[i]-'0');
            if(i<a.s.size())
                temp+=(a.s[i]-'0');
            if(carry){
                temp++;
                carry=false;
            }
            if(temp>=10){
                temp-=10;
                carry=true;
            }
            res+=(temp+'0');
        }
        if(carry)
            res+='1';
        return res;
    }
    void print(){
        for(string::reverse_iterator itr=s.rbegin();itr!=s.rend();itr++)
            cout<<*itr;
        cout<<endl;
    }
};
signed main(){
    int n,m;
    cin>>n>>m;
    MAX_NUMBER a("1");
    MAX_NUMBER b("1");
    MAX_NUMBER ans;
    for(int i=2;i<m-n+1;i++){
        ans=a+b;
        a=b;
        b=ans;
    }
    ans.print();    
    return 0;
}