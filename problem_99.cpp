// https://www.luogu.com.cn/problem/P4017   ©Ý¾ë±Æ§Ç(DFS)+dp
#include <bits/stdc++.h>
#define mod 80112002
using namespace std;
void dfs(int i,vector<vector<int>> &edge,vector<bool> &run,stack<int> &st){
    run[i]=true;
    for(int j=0;j<edge[i].size();j++){
        if(!run[edge[i][j]]){
            dfs(edge[i][j],edge,run,st);
        }
    }
    st.push(i);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> edge(n);
    vector<vector<int>> reverse_edge(n);
    vector<int> degree(n,0);
    vector<int> reverse_degree(n,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        edge[b].push_back(a);
        reverse_edge[a].push_back(b);
        degree[a]++;
        reverse_degree[b]++;
    }
    stack<int> st;
    vector<bool> run(n,false);
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        if(degree[i]==0)
            dfs(i,edge,run,st);
    }
    while(!st.empty()){
        if(degree[st.top()]==0)
            dp[st.top()]=1;
        else{
            for(int j=0;j<reverse_edge[st.top()].size();j++)
                dp[st.top()]=(dp[st.top()]+dp[reverse_edge[st.top()][j]])%mod;
        }
        st.pop();
    }
    int ans=0;
    for(int i=0;i<n;i++)
        if(reverse_degree[i]==0)
            ans=(ans+dp[i])%mod;
    cout<<ans<<'\n';
    return 0;
}
/*

*/