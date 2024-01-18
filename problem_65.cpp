// https://www.luogu.com.cn/problem/P1896    狀態壓縮DP
#include <bits/stdc++.h>
using namespace std;
bool check(int x,int y,int n){
    for(int i=0;i<n;i++)
        if(x>>i&1)
            if((0<=i-1 && (y>>(i-1)&1)) || (y>>i&1) || (i+1<n && (y>>(i+1)&1)))
                return true;
    return false;
}
int main(){
    long long ans=0;
    int n,k;
    cin>>n>>k;
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(1<<n,vector<long long>(max(k,n)+1,0)));     //dp[i][j][k] = 前i行 第i行狀態為j 用了k個國王 的方案數  
    vector<pair<int,int>> state;        //      可能狀態/此狀態下1的個數
    for(int i=0;i<(1<<n);i++){
        bool flag=false;
        int temp=i&1;
        for(int j=1;j<n;j++){
            flag|=(i>>(j-1)&1) && (i>>j&1);
            temp+=(i>>j&1);
        }
        if(flag) 
            continue;
        state.push_back({i,temp});
    }
    // for(int i=0;i<state.size();i++)
    //     cout<<state[i].first<<' '<<state[i].second<<endl;
    for(int i=0;i<state.size();i++)
        dp[0][state[i].first][state[i].second]++;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<state.size();j++){
            for(int x=k;x>=0;x--){
                if(x<state[j].second)
                    break;
                for(int y=0;y<state.size();y++){
                    if(check(state[j].first,state[y].first,n)) //衝突
                        continue;
                    dp[i][state[j].first][x]+=dp[i-1][state[y].first][x-state[j].second];
                }
            }
        }
    }
    for(int i=0;i<state.size();i++)
        ans+=dp[n-1][state[i].first][k];
    cout<<ans<<endl;
    return 0;
}