// https://www.luogu.com.cn/problem/P1433   狀壓DP
#include <bits/stdc++.h>
using namespace std;
double dis(pair<double,double> a,pair<double,double> b){
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,temp;
    cin>>n;
    vector<pair<double,double>> point(n);
    vector<vector<vector<double>>> dp(n,vector<vector<double>>(1<<n,vector<double>(n,1e6)));   //dp[i][j][k] 已連接i個點 狀態為j(有哪些點) 第k個點結尾
    vector<vector<int>> state(n);
    for(int i=0;i<n;i++)
        cin>>point[i].first>>point[i].second;
    for(int i=1;i<(1<<n);i++){
        temp=0;
        for(int j=0;j<n;j++)
            temp+=(i>>j&1);
        state[temp-1].push_back(i);
    }
    for(int i=0;i<n;i++){
        dp[0][1<<i][i]=dis({0,0},point[i]);
        // cout<<dp[0][1<<i][i]<<endl;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<state[i].size();j++){
            // state[i][j]
            for(int k=0;k<n;k++){
                if(state[i][j]>>k&1){
                    temp=state[i][j]&(~(1<<k));
                    for(int x=0;x<n;x++){
                        if(temp>>x&1){
                            // cout<<state[i][j]<<" :"<<k<<' '<<x<<' '<<dp[i][state[i][j]][k]<<' '<<dis(point[k],point[x]);
                            dp[i][state[i][j]][k]=min(dp[i][state[i][j]][k],dp[i-1][temp][x]+dis(point[k],point[x]));
                            // cout<<' '<<dp[i][state[i][j]][k]<<endl;
                        }
                    }
                }
            }
        }
    }
    double ans=1e6;
    for(int i=0;i<n;i++)
        ans=min(ans,dp[n-1][(1<<n)-1][i]);
    printf("%.2f\n",ans);
    return 0;
}