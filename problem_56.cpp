// https://www.luogu.com.cn/problem/P1162
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void dfs(int i,int j,vector<vector<int>> &map,vector<vector<bool>> &run){
    run[i][j]=true;
    if(i+1<run.size() && !run[i+1][j] && !map[i+1][j])
        dfs(i+1,j,map,run);
    if(j+1<run.size() && !run[i][j+1] && !map[i][j+1])
        dfs(i,j+1,map,run);
    if(0<i && !run[i-1][j] && !map[i-1][j])
        dfs(i-1,j,map,run);
    if(0<j && !run[i][j-1] && !map[i][j-1])
        dfs(i,j-1,map,run);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<vector<bool>> run(n,vector<bool>(n,false));
    vector<vector<int>> map(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    for(int i=0;i<n;i++)
        if(!run[0][i] && !map[0][i])
            dfs(0,i,map,run);  
    for(int i=0;i<n;i++)
        if(!run[i][0] && !map[i][0])
            dfs(i,0,map,run);  
    for(int i=0;i<n;i++)
        if(!run[n-1][i] && !map[n-1][i])
            dfs(n-1,i,map,run);  
    for(int i=0;i<n;i++)
        if(!run[i][n-1] && !map[i][n-1])
            dfs(i,n-1,map,run); 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!run[i][j] && !map[i][j])
                map[i][j]=2;
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}