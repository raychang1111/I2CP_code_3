// https://www.luogu.com.cn/problem/P1605
#include <bits/stdc++.h>
using namespace std;
int dfs(int sx,int sy,int fx,int fy,vector<vector<bool>> &run){
    if(sx==fx && sy==fy)
        return 1;
    int res=0;
    run[sx][sy]=true;
    if(sx+1<run.size() && !run[sx+1][sy])
        res+=dfs(sx+1,sy,fx,fy,run);
    if(sy+1<run[0].size() && !run[sx][sy+1])
        res+=dfs(sx,sy+1,fx,fy,run);
    if(0<=sx-1 && !run[sx-1][sy])
        res+=dfs(sx-1,sy,fx,fy,run);
    if(0<=sy-1 && !run[sx][sy-1])
        res+=dfs(sx,sy-1,fx,fy,run);
    run[sx][sy]=false;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,t,sx,sy,fx,fy,temp1,temp2;
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    vector<vector<bool>> run(n,vector<bool>(m,false));
    for(int i=0;i<t;i++){
        cin>>temp1>>temp2;
        run[temp1-1][temp2-1]=true;
    }
    cout<<dfs(sx-1,sy-1,fx-1,fy-1,run)<<'\n';
    return 0;
}