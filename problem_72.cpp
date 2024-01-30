// https://www.luogu.com.cn/problem/P1443
#include <bits/stdc++.h>
using namespace std;
void bfs(int x,int y,int val,vector<vector<int>> &dp){
    queue<vector<int>> Q;
    Q.push({x,y,val});
    while(!Q.empty()){
        x=Q.front()[0],y=Q.front()[1],val=Q.front()[2];
        Q.pop();
        if(dp[x][y]==-1 || dp[x][y]>val){
            dp[x][y]=val;
            if(x+1<dp.size() && y+2<dp[0].size())
                Q.push({x+1,y+2,val+1});
            if(x+2<dp.size() && y+1<dp[0].size())
                Q.push({x+2,y+1,val+1});
            if(x+1<dp.size() && 0<=y-2)
                Q.push({x+1,y-2,val+1});
            if(x+2<dp.size() && 0<=y-1)
                Q.push({x+2,y-1,val+1});
            if(0<=x-1 && 0<=y-2)
                Q.push({x-1,y-2,val+1});
            if(0<=x-2 && 0<=y-1)
                Q.push({x-2,y-1,val+1});
            if(0<=x-1 && y+2<dp[0].size())
                Q.push({x-1,y+2,val+1});
            if(0<=x-2 && y+1<dp[0].size())
                Q.push({x-2,y+1,val+1});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    bfs(x-1,y-1,0,dp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}