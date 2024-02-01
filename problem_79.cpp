// https://www.luogu.com.cn/problem/P1596
#include <bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<bool>> &map){
    if(!map[i][j])
        return ;
    bool d[4]={(i!=0),(i+1!=map.size()),(j!=0),(j+1!=map[0].size())};
    map[i][j]=false;
    if(d[0])
        dfs(i-1,j,map);
    if(d[1])
        dfs(i+1,j,map);
    if(d[2])
        dfs(i,j-1,map);
    if(d[3])
        dfs(i,j+1,map);
    if(d[0] && d[2])
        dfs(i-1,j-1,map);
    if(d[0] && d[3])
        dfs(i-1,j+1,map);
    if(d[1] && d[2])
        dfs(i+1,j-1,map);
    if(d[1] && d[3])
        dfs(i+1,j+1,map);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    char c;
    int n,m,ans=0;
    cin>>n>>m;
    vector<vector<bool>> map(n,vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin>>c;
           map[i][j]=(c=='W'); 
        }
    }
    // dfs(0,9,map);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]){
                ans++;
                dfs(i,j,map);
            }
            // cout<<map[i][j];
        }
        // cout<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}