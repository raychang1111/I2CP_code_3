// https://www.luogu.com.cn/problem/P1049
#include <bits/stdc++.h>
using namespace std;
int main(){
    int v,n;
    cin>>v>>n;
    vector<int> nums(n);    
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<vector<int>> dp(n,vector<int>(v+1));
    for(int i=0;i<n;i++)
        dp[i][0]=0;
    for(int j=0;j<=v;j++){
        if(j<nums[0])
            dp[0][j]=j;
        else
            dp[0][j]=j-nums[0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=v;j++){
            if(j>=nums[i])
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-nums[i]]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=v;j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<dp[n-1][v]<<'\n';
    return 0;
}
// dp[i][j] 0~i項物品選擇放入j空間的箱子剩餘空間
// dp[i][j]=min(dp[i-1][j],dp[i-1][j-nums[i]]-nums[i]s)