// https://www.luogu.com.cn/problem/P1802
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<vector<int>> nums(n+1,vector<int>(3));
    for(int i=1;i<=n;i++)
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++)
        dp[i][0]=dp[i-1][0]+nums[i][0];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j>=nums[i][2])
                dp[i][j]=max(dp[i-1][j]+nums[i][0],dp[i-1][j-nums[i][2]]+nums[i][1]);
            else
                dp[i][j]=dp[i-1][j]+nums[i][0];     
            // cout<<dp[i][j]<<' ';   
        }
        // cout<<endl;
    }
    cout<<dp[n][x]*5<<'\n';
    return 0;
}
// dp[i][j] 在1~i位朋友中，有j藥瓶的最大經驗