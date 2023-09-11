// https://www.luogu.com.cn/problem/P1164   
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int dfs(int m,int i,vector<int> &data,vector<vector<int>> &dp){
    if(m<1)
        return m==0? 1:0;
    if(i<data.size() && dp[m][i]!=-1)
        return dp[m][i];
    int res=0;
    for(int j=i;j<data.size();j++)
        res+=dfs(m-data[j],j+1,data,dp);
    return dp[m][i]=res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> data(n);
    vector<vector<int>> dp(m+1,vector<int>(n,-1));
    for(int i=0;i<n;i++)
        cin>>data[i];
    cout<<dfs(m,0,data,dp)<<endl;
    return 0;
}