// https://www.luogu.com.cn/problem/P1434
#include <bits/stdc++.h>
using namespace std;
int dfs(int i,int j,vector<vector<int>> &map,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)
        return dp[i][j];
    bool up=(0<=i-1 && map[i-1][j]<map[i][j]);
    bool down=(i+1<map.size() && map[i+1][j]<map[i][j]);
    bool left=(0<=j-1 && map[i][j-1]<map[i][j]);
    bool right=(j+1<map[0].size() && map[i][j+1]<map[i][j]);
    int res=0;
    if(up)
        res=max(res,dfs(i-1,j,map,dp));
    if(down)
        res=max(res,dfs(i+1,j,map,dp));
    if(left)
        res=max(res,dfs(i,j-1,map,dp));
    if(right)
        res=max(res,dfs(i,j+1,map,dp));
    return dp[i][j]=res+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    vector<vector<int>> map(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>map[i][j];
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans=max(ans,dfs(i,j,map,dp));
    cout<<ans<<'\n';
    return 0;
}
//dp[i][j] 在座標為ij位置的最長滑坡長度