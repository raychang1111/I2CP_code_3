// https://www.luogu.com.cn/problem/P2241
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,ans1=0,ans2=0;
    cin>>n>>m;
    if(n>m)
        swap(n,m);
    for(long long i=1;i<=n;i++)
        ans1+=(n-i+1)*(m-i+1);
    for(long long i=1;i<m;i++){
        for(long long j=1;j<=n && j+i<=m;j++)
            ans2+=(n-j+1)*(m-j-i+1);
        for(long long j=1;j<=m && j+i<=n;j++)
            ans2+=(m-j+1)*(n-j-i+1);
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}