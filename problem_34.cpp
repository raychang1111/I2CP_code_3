// https://www.luogu.com.cn/problem/P1990           難點: 遞迴式找不到  (值得回味)
#include <bits/stdc++.h>
using namespace std;
const int mod=1e4;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n,1);
    vector<int> dp_1(n,1);
    if(1<n){
        dp[1]=2;
        dp_1[1]=2;
    }
    for(int i=2;i<n;i++){
        dp[i]=(dp[i-1]+dp[i-2]+2*dp_1[i-2])%mod;
        dp_1[i]=(dp_1[i-1]+dp[i-1])%mod;
    }
    cout<<dp.back()<<endl;
    return 0;
}