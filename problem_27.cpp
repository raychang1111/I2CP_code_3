// https://www.luogu.com.cn/problem/P1002
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<vector<bool>> enable(n+1,vector<bool>(m+1,false));
    if(0<=a-2 && 0<=b-1)
        enable[a-2][b-1]=true;
    if(0<=a-2 && b+1<=m)
        enable[a-2][b+1]=true;
    if(a+2<=n && 0<=b-1)
        enable[a+2][b-1]=true;
    if(a+2<=n && b+1<=m)
        enable[a+2][b+1]=true;
    if(0<=b-2 && 0<=a-1)
        enable[a-1][b-2]=true;
    if(0<=b-2 && a+1<=n)
        enable[a+1][b-2]=true;
    if(b+2<=m && 0<=a-1)
        enable[a-1][b+2]=true;
    if(b+2<=m && a+1<=n)
        enable[a+1][b+2]=true;
    enable[a][b]=true;    
    for(int i=1;i<=n && !enable[i][0];i++)
        dp[i][0]=1;
    for(int j=1;j<=m && !enable[0][j];j++)
        dp[0][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(enable[i][j])
                continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}