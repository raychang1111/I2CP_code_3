// https://www.luogu.com.cn/problem/P1216   dp ºu°Ê¼Æ²Õ
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int r,ans=0;
    cin>>r;
    vector<vector<int>> dp(2,vector<int>(r));
    bool dp_ptr=false;
    cin>>dp[dp_ptr][0];
    dp_ptr=!dp_ptr;
    for(int i=1;i<r;i++){
        for(int j=0;j<=i;j++){
            cin>>dp[dp_ptr][j];
            if(j==0)
                dp[dp_ptr][j]+=dp[!dp_ptr][j];
            else if(j==i)
                dp[dp_ptr][j]+=dp[!dp_ptr][j-1];
            else
                dp[dp_ptr][j]+=max(dp[!dp_ptr][j-1],dp[!dp_ptr][j]);
            // cout<<dp[dp_ptr][j]<<' ';
            ans=max(ans,dp[dp_ptr][j]);
        }
        // cout<<endl;
        dp_ptr=!dp_ptr;
    }
    cout<<ans<<'\n';
    return 0;
}
// 0 1 2 3 4 5 6
//    0
//   1 2
//  3 4 6 
