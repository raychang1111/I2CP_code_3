// https://www.luogu.com.cn/problem/P2895
#include <bits/stdc++.h>
using namespace std;
bool cmp_self(vector<int> &a,vector<int>&b){
    return a[2]<b[2];
}
int bfs(vector<vector<int>> &arr,int m){
    int n,t=0,j=0;
    vector<vector<int>> dp(m,vector<int>(m,INT_MAX));         //dp[i][j] 移動到座標ij的最小時間
    queue<vector<int>> Q;
    Q.push({0,0});
    while(!Q.empty() || j<arr.size()){
        n=Q.size();
        while(j<arr.size() && arr[j][2]==t){
            dp[arr[j][0]][arr[j][1]]=-1;
            if(0<=arr[j][0]-1)
                dp[arr[j][0]-1][arr[j][1]]=-1;
            if(0<=arr[j][1]-1)
                dp[arr[j][0]][arr[j][1]-1]=-1;
            if(arr[j][0]+1<dp.size())
                dp[arr[j][0]+1][arr[j][1]]=-1;
            if(arr[j][1]+1<dp.size())
                dp[arr[j][0]][arr[j][1]+1]=-1;
            j++;
        }
        for(int i=0;i<n;i++){
            if(dp[Q.front()[0]][Q.front()[1]]>t){
                dp[Q.front()[0]][Q.front()[1]]=t;
                if(Q.front()[0]+1<dp.size())
                    Q.push({Q.front()[0]+1,Q.front()[1]});
                if(Q.front()[1]+1<dp.size())
                    Q.push({Q.front()[0],Q.front()[1]+1});
                if(0<=Q.front()[0]-1)
                    Q.push({Q.front()[0]-1,Q.front()[1]});
                if(0<=Q.front()[1]-1)
                    Q.push({Q.front()[0],Q.front()[1]-1});
            }
            Q.pop();
        }
        t++;
    }
    t=INT_MAX;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp.size();j++){
            if(dp[i][j]!=-1)
                t=min(t,dp[i][j]);
        }
    }
    return t==INT_MAX? -1:t;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m=0;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        m=max({m,arr[i][0],arr[i][1],arr[i][2]});
    }
    sort(arr.begin(),arr.end(),cmp_self);
    cout<<bfs(arr,m+1)<<'\n';
    return 0;
}
