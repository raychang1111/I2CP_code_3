// https://www.luogu.com.cn/problem/P1352  (基本 樹形DP)
#include <bits/stdc++.h>
using namespace std;
int dfs(int i,vector<int> &happiness_value,vector<vector<int>> &link,vector<vector<int>> &dp){
    vector<int> sum(2,0);
    for(int j=0;j<link[i].size();j++){
        dfs(link[i][j],happiness_value,link,dp);
        sum[0]+=dp[link[i][j]][0];                  //子root不能來
        sum[1]+=max(dp[link[i][j]][1],dp[link[i][j]][0]);   //因為主管不來 所以子root可來可不來
    }
    dp[i][0]=sum[1];
    dp[i][1]=sum[0]+happiness_value[i];
    // cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    return max(dp[i][0],dp[i][1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n;
    vector<int> happiness_value(n);
    for(int i=0;i<n;i++)
        cin>>happiness_value[i];
    vector<vector<int>> link(n);
    vector<bool> is_root(n,true);
    for(int i=1;i<n;i++){
        cin>>a>>b;
        a--;
        b--;
        link[b].push_back(a);
        is_root[a]=false;
    }
    int ans=0;
    vector<vector<int>> dp(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        if(is_root[i]){
            ans+=dfs(i,happiness_value,link,dp);
        }
    }
    cout<<ans<<'\n';
    return 0;
}