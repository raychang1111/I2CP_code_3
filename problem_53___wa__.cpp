// https://www.luogu.com.cn/problem/P1080       //大數  待處理  未完
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(pair<long long,long long> a,pair<long long,long long> b){
    return a.first*a.second < b.first*b.second;
}
class big_ll{
public:
    string s;
    static string itos(long long a){
        string res;
        while(a){
            res+=('0'+a%10);
            a/=10;
        }
        return res;
    }
    big_ll(){
        s="";
    }
    big_ll(long long a,int zero){
        string bs="0";
        while(zero){
            if(zero&1)
                s=s+bs;
            bs=bs+bs;
            zero>>=1;
        }
        s+=itos(a);
        while(s.size()>1 && s.back()=='0')
            s.pop_back();
    }
    big_ll(big_ll &a){
        s=a.s;
    }
    big_ll operator+(big_ll &a){
        big_ll res;
        bool carry=false;
        int temp;
        for(int j=0;j<max(s.size(),a.s.size());j++){
            temp=0;
            if(j<s.size())
                temp+=(s[j]-'0');
            if(j<a.s.size())
                temp+=(a.s[j]-'0');
            if(carry){
                temp++;
                carry=false;
            }
            if(temp>=10){
                temp-=10;
                carry=true;
            }
            res.s+=(temp+'0');
        }
        if(carry)
            res.s+='1';
        return res;
    }
    big_ll operator*(int k){            //k= 1~10
        big_ll res,temp;
        int zero=0;
        for(int i=0;i<s.size();i++){
            temp=big_ll((s[i]-'0')*k,zero);
            res=res+temp;
            zero++;
        }
        return res;
    }
    big_ll operator/(big_ll a){
        
    }
    void print(){
        for(int i=s.size()-1;i>=0;i--)
            cout<<s[i];
        cout<<endl;
    }
};
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    // long long n,ans=0;
    // cin>>n;
    // pair<long long,long long> curr;
    // vector<pair<long long,long long>> arr(n);
    // cin>>curr.first>>curr.second;
    // for(long long i=0;i<n;i++)
    //     cin>>arr[i].first>>arr[i].second;
    // sort(arr.begin(),arr.end(),cmp);
    // for(long long i=0;i<n;i++){
    //     ans=max(ans,curr.first/arr[i].second);
    //     curr.first*=arr[i].first;
    // }
    // cout<<ans<<endl;
    big_ll A(2,2);
    big_ll B(312,0);
    // A.print();
    B.print();
    // (A+B).print();
    (B*9).print();
    return 0;
}