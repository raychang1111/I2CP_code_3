// https://www.luogu.com.cn/problem/P3842
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>arr[i][0]>>arr[i][1];
    vector<vector<int>> dp(n,vector<int>(2));
    dp[0][0]=arr[0][1]-arr[0][0]+arr[0][1]-1;
    dp[0][1]=arr[0][1]-arr[0][0]+arr[0][0]-1;
    for(int i=1;i<n;i++){
        a=abs(arr[i-1][1]-arr[i][1])+dp[i-1][1];
        b=abs(arr[i-1][0]-arr[i][1])+dp[i-1][0];
        c=abs(arr[i-1][1]-arr[i][0])+dp[i-1][1];
        d=abs(arr[i-1][0]-arr[i][0])+dp[i-1][0];
        if(a<b)
            dp[i][0]=arr[i][1]-arr[i][0]+a+1;
        else    
            dp[i][0]=arr[i][1]-arr[i][0]+b+1;
        if(c<d)
            dp[i][1]=arr[i][1]-arr[i][0]+c+1;
        else
            dp[i][1]=arr[i][1]-arr[i][0]+d+1;
    }
    // for(int i=0;i<n;i++)
    //     cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    a=abs(arr[n-1][0]-n);
    b=abs(arr[n-1][1]-n);
    cout<<min(dp[n-1][0]+a,dp[n-1][1]+b)<<'\n';
    return 0;
}
// dp[i][j] 走完第i行最後停在j的最小路徑
// temp=min(arr[i][0]-arr[i-1][0],arr[i][1]-arr[i-1][0])
// dp[i][j]=min(dp[i-1][0],dp[i-1][1])