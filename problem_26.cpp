// https://www.luogu.com.cn/problem/P1255    //手刻大數運算 (+)
#include <bits/stdc++.h>
#define int long long
using namespace std;
class MAX_NUMBER{
public:
    string x;
    MAX_NUMBER(){
        x="0";
    }
    MAX_NUMBER(string a){
        x=a;
    }
    MAX_NUMBER(MAX_NUMBER &a){
        x=a.x;
    }
    MAX_NUMBER operator+(MAX_NUMBER &a){
        int temp;
        bool carry=false;
        string res;
        for(int i=0;i<max(this->x.size(),a.x.size());i++){
            temp=0;
            if(i < this->x.size())
                temp+=(this->x[i]-'0');
            if(i < a.x.size())
                temp+=(a.x[i]-'0');
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
        return MAX_NUMBER(res);
    }
    void print(){
        for(int i=x.size()-1;i>=0;i--)
            cout<<x[i];
    }
};
signed main(){
    int n;
    cin>>n;
    if(n==1)
        cout<<1<<endl;
    else if(n==2)
        cout<<2<<endl;
    else{
        MAX_NUMBER a("1");
        MAX_NUMBER b("2");
        MAX_NUMBER ans;
        for(int i=3;i<=n;i++){
            ans=a+b;
            a=b;
            b=ans;
        }
        ans.print();
        cout<<endl;
    }
    return 0;
}