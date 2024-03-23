#include <bits/stdc++.h>
#define mod 1000007
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n,vector<int>(m+1,0));
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int j=1;j<=min(m,arr[0]);j++)
        dp[0][j]=1;
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=arr[i] && k<=j;k++){
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<=m;j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<dp[n-1][m]<<endl;
    return 0;
}
// dp[i][j] 使用0~i種花，擺滿j盆的方案數(同一種花放在一起，且不同種類的花需依標號的從小到大的順序依序擺列)
// dp[i][j]=dp[i-1][j]+dp[i-1][j-1]..+dp[i-1][j-arr[i]]
// dp[2][1]=dp[1][1]+dp[1][0]