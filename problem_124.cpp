// https://www.luogu.com.cn/problem/P1495 (中國剩餘定理 模板題)
#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    long long res=exgcd(b,a%b,x,y);
    long long new_x=y;
    long long new_y=x-a/b*y;
    x=new_x;
    y=new_y;
    return res;
}
long long inv(long long a,long long p){
    long long x,y;
    exgcd(a,p,x,y);
    return (x%p+p)%p;       //注意
}
long long CRT(int k,vector<long long> &a,vector<long long> &p){
    long long n=1,ans=0;
    for(int i=0;i<k;i++)
        n*=p[i];
    for(int i=0;i<k;i++){
        long long m=n/p[i];
        ans=(ans+(a[i]*(m))%n*inv(m,p[i])%n)%n;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<long long> p(n);
    vector<long long> a(n);
    for(int i=0;i<n;i++)
        cin>>p[i]>>a[i];
    cout<<CRT(n,a,p)<<'\n';
    return 0;
}