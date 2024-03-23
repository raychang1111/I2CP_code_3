// https://www.luogu.com.cn/problem/P4913
#include <bits/stdc++.h>
using namespace std;
int bfs(int start,vector<vector<int>> &link){
    queue<int> Q;   
    Q.push(start);
    int deep=0;
    while(!Q.empty()){
        int m=Q.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<link[Q.front()].size();j++)
                Q.push(link[Q.front()][j]);
            Q.pop();
        }
        deep++;
    }
    return deep;
}
int main(){
    int n,a,b,ans=0;
    cin>>n;
    vector<int> arr(n);
    vector<vector<int>> link(n);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a!=0){
            link[i].push_back(--a);
            arr[a]++;
        }
        if(b!=0){
            link[i].push_back(--b);
            arr[b]++;
        }
    }
    for(int i=0;i<n;i++)
        if(arr[i]==0)
            ans=max(ans,bfs(i,link));
    cout<<ans<<'\n';
    return 0;
}