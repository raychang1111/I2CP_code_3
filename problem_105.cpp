// https://www.luogu.com.cn/problem/P1064
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>m>>n;
    vector<vector<int>> nums(n,vector<int>(3));
    for(int i=0;i<n;i++)
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    vector<vector<int>> link(n);
    vector<int> arr;
    for(int i=0;i<n;i++){
        if(nums[i][2]!=0)
            link[nums[i][2]-1].push_back(i);
        else
            arr.push_back(i);
    }
    vector<vector<int>> dp(arr.size()+1,vector<int>(m+1,0));
    for(int i=1;i<=arr.size();i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            for(int k=0;k<(1<<link[arr[i-1]].size());k++){
                a=nums[arr[i-1]][0];
                b=nums[arr[i-1]][0]*nums[arr[i-1]][1];
                for(int x=0;x<link[arr[i-1]].size();x++){
                    if(k>>x&1){
                        a+=nums[link[arr[i-1]][x]][0];
                        b+=nums[link[arr[i-1]][x]][0]*nums[link[arr[i-1]][x]][1];
                    }
                    if(j<a)
                        break;
                }
                if(j>=a){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-a]+b);
                }
            }
            // cout<<dp[i][j]<<' ';
        }   
        // cout<<'\n';
    }
    cout<<dp[arr.size()][m]<<'\n';
    return 0;
}
// dp[i][j] 在第0~i個主件與其副件中，再不超過j元的前提下，重要度乘價格為最大值
// dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i][0]]+nums[i][0]*nums[i][1]...);