// https://www.luogu.com.cn/problem/P1469
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans=0,a;
    cin>>n;
    while(n--){
        cin>>a;
        ans^=a;
    }
    cout<<ans<<'\n';
    return 0;
}