// https://www.luogu.com.cn/problem/P1879    ª¬À£DP
#include <bits/stdc++.h>
#define MOD (long long)1e8
using namespace std;
int main(){
    long long ans=0;
    int n,m,temp;
    cin>>n>>m;
    vector<int> Land_Availability(n,0);
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(1<<m,vector<long long>((n*m)/2+1,0)));
    vector<pair<int,int>> state;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            Land_Availability[i]|=(temp<<j);
        }
    }
    for(int i=0;i<(1<<m);i++){
        bool flag=false;
        temp=i&1;
        for(int j=1;j<m && !flag;j++){
            flag=(i>>(j-1)&1) && (i>>j&1);
            temp+=i>>j&1;
        }
        if(flag)    
            continue;
        state.push_back({i,temp});
        // cout<<i<<' '<<temp<<endl;
    }
    for(int i=0;i<state.size();i++){
        if((Land_Availability[0]&state[i].first)!=state[i].first)
            continue;
        dp[0][state[i].first][state[i].second]++;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<state.size();j++){
            if((Land_Availability[i]&state[j].first)!=state[j].first)
                continue;
            for(int k=(n*m)/2;k>=0;k--){
                if(k<state[j].second)
                    continue;
                for(int x=0;x<state.size();x++){
                    bool flag=false;    // ¬O§_½Ä¬ð
                    for(int y=0;y<m && !flag;y++)
                        flag=(state[j].first>>y&1) && (state[x].first>>y&1);
                    if(flag)
                        continue;
                    dp[i][state[j].first][k]=(dp[i][state[j].first][k]+dp[i-1][state[x].first][k-state[j].second])%MOD;
                }
            }
        }
    }
    for(int i=0;i<state.size();i++)
        for(int k=0;k<(n*m)/2+1;k++)
            ans=(ans+dp[n-1][state[i].first][k])%MOD;
    cout<<ans<<endl;
    return 0;
}