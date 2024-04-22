// https://www.luogu.com.cn/problem/P3811   (求模逆元) (若p為質數 且a p互質 則 a的逆元為 a^(p-2))
#include <bits/stdc++.h>
using namespace std;
long long pow(long long x,long long y,long long p){
    long long res=1;
    while(y){
        if(y&1)
            res=(res*x)%p;
        x=(x*x)%p;
        y>>=1;
    }
    return res;
}
void main_1(){
    long long n,p;
    cin>>n>>p;
    for(long long i=1;i<=n;i++)
        cout<<pow(i,p-2,p)<<'\n';
}
void main_2(){
    long long n,p;
    cin>>n>>p;
    vector<long long> inv(n+1);
    inv[0]=0;
    inv[1]=1;
    cout<<inv[1]<<'\n';
    for(int i=2;i<=n;i++)
        cout<<(inv[i]=((-p/i)*inv[p%i]%p+p)%p)<<'\n';
}
int main(){
    // main_1(); TLE
    main_2();
    return 0;
}
