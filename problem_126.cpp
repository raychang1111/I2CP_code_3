// https://www.luogu.com.cn/problem/P1029
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    return b? gcd(b,a%b):a;
}
int main(){
    long long x,y,n,ans=0;
    cin>>x>>y;
    n=x*y;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0){
            if(gcd(i,(n/i))==x)
                ans+=2;
        }
    }
    if(x==y){
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}