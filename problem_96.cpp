// https://www.luogu.com.cn/problem/P1048
#include <bits/stdc++.h>
#define time first
#define val second
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,m;
    cin>>t>>m;
    vector<pair<int,int>> arr(m);
    vector<vector<int>> dp(m+1,vector<int>(t+1,0));
    for(int i=0;i<m;i++){
        cin>>arr[i].time>>arr[i].val;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            if(j>=arr[i-1].time)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1].time]+arr[i-1].val);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[m][t]<<'\n';
    return 0;
}
// dp[i][j] 0~i種草藥在時間j下的最大價值
// dp[i][j]= (dp[i-1][j],dp[i-1][j-arr[i].t]+arr[i].v);