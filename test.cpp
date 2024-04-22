#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;
    y--;
    vector<vector<int>> dis(n,vector<int>(m,1e9));
    queue<pair<int,int>> Q;
    Q.push({x,y});
    dis[x][y]=0;
    while(!Q.empty()){
        int temp=dis[Q.front().first][Q.front().second];
        // Q.front().first  Q.front().second;
        // +2 +1 
        // +2 -1
        // -2 +1
        // -2 -1
        // +1 +2
        // -1 +2
        // +1 -2
        // -1 -2
        if(Q.front().first+2<n && Q.front().second+1<m && dis[Q.front().first+2][Q.front().second+1]>temp+1){
            dis[Q.front().first+2][Q.front().second+1]=temp+1;
            Q.push({Q.front().first+2,Q.front().second+1});
        }
        if(Q.front().first+2<n && 0<=Q.front().second-1 && dis[Q.front().first+2][Q.front().second-1]>temp+1){
            dis[Q.front().first+2][Q.front().second-1]=temp+1;
            Q.push({Q.front().first+2,Q.front().second-1});
        }  
        if(0<=Q.front().first-2 && Q.front().second+1<m && dis[Q.front().first-2][Q.front().second+1]>temp+1){
            dis[Q.front().first-2][Q.front().second+1]=temp+1;
            Q.push({Q.front().first-2,Q.front().second+1});
        }
        if(0<=Q.front().first-2 && 0<=Q.front().second-1 && dis[Q.front().first-2][Q.front().second-1]>temp+1){
            dis[Q.front().first-2][Q.front().second-1]=temp+1;
            Q.push({Q.front().first-2,Q.front().second-1});
        } 
        if(Q.front().first+1<n && Q.front().second+2<m && dis[Q.front().first+1][Q.front().second+2]>temp+1){
            dis[Q.front().first+1][Q.front().second+2]=temp+1;
            Q.push({Q.front().first+1,Q.front().second+2});
        }
        if(Q.front().first+1<n && 0<=Q.front().second-2 && dis[Q.front().first+1][Q.front().second-2]>temp+1){
            dis[Q.front().first+1][Q.front().second-2]=temp+1;
            Q.push({Q.front().first+1,Q.front().second-2});
        }  
        if(0<=Q.front().first-1 && Q.front().second+2<m && dis[Q.front().first-1][Q.front().second+2]>temp+1){
            dis[Q.front().first-1][Q.front().second+2]=temp+1;
            Q.push({Q.front().first-1,Q.front().second+2});
        }
        if(0<=Q.front().first-1 && 0<=Q.front().second-2 && dis[Q.front().first-1][Q.front().second-2]>temp+1){
            dis[Q.front().first-1][Q.front().second-2]=temp+1;
            Q.push({Q.front().first-1,Q.front().second-2});
        } 
        Q.pop();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dis[i][j]==1e9)
                cout<<-1<<' ';
            else
                cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}