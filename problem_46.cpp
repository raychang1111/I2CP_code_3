// https://cses.fi/problemset/task/1131
#include <bits/stdc++.h>
using namespace std;
pair<int,int> dfs(int i,vector<vector<int>> &link,vector<bool> &run){   //離 i 的最遠距離 跟 節點
    run[i]=true;
    pair<int,int> res={0,-1},temp;
    for(int j=0;j<link[i].size();j++){
        if(!run[link[i][j]]){
            temp=dfs(link[i][j],link,run);
            if(res.first<temp.first)
                res=temp;
        }
    }
    if(res.first==0 && res.second==-1)
        res.second=i;
    res.first++;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n;
    vector<vector<int>> link(n);
    while(cin>>a>>b){
        a--;
        b--;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    vector<bool> run(n,false);
    int root=dfs(0,link,run).second;
    for(int i=0;i<n;i++)
        run[i]=false;
    cout<<dfs(root,link,run).first-1<<'\n';
    return 0;
}