// https://www.luogu.com.cn/problem/P1044
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
        dp[0][i]=1;
    for(int i=1;i<=n;i++){
        dp[i][i]=dp[i-1][i];
        for(int j=i+1;j<=n;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
    cout<<dp[n][n]<<endl;
    return 0;
}