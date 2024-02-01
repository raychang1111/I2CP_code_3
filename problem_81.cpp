// https://www.luogu.com.cn/problem/P1825       
#include <bits/stdc++.h>
using namespace std;
int bfs(pair<int,int> start,vector<vector<char>> &map,vector<vector<vector<int>>> &transmit){
    int n,val=0,x,y;
    vector<vector<int>> dp(map.size(),vector<int>(map[0].size(),INT_MAX));  //dp[i][j] 從起點走到ij的步數
    queue<pair<int,int>> Q;
    Q.push(start);
    while(!Q.empty()){
        n=Q.size();
        for(int i=0;i<n;i++){
            x=Q.front().first;
            y=Q.front().second;
            if(map[x][y]=='=')
                return val;
            if(dp[x][y]>val){
                if('A'<=map[x][y] && map[x][y]<='Z'){
                    int temp_x,temp_y;
                    if(transmit[map[x][y]-'A'][0][0]==x && transmit[map[x][y]-'A'][0][1]==y){
                        temp_x=transmit[map[x][y]-'A'][1][0];
                        temp_y=transmit[map[x][y]-'A'][1][1];
                    }
                    else{
                        temp_x=transmit[map[x][y]-'A'][0][0];
                        temp_y=transmit[map[x][y]-'A'][0][1];
                    }
                    x=temp_x;
                    y=temp_y;
                }
                else
                    dp[x][y]=val;
                if(x+1<map.size() && map[x+1][y]!='#')
                    Q.push({x+1,y});
                if(y+1<map[0].size() && map[x][y+1]!='#')
                    Q.push({x,y+1});
                if(0<=x-1 && map[x-1][y]!='#')
                    Q.push({x-1,y});
                if(0<=y-1 && map[x][y-1]!='#')
                    Q.push({x,y-1});
            }
            Q.pop();
        }
        val++;
    }
    
    return -1;  //到不了
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pair<int,int> start;
    vector<vector<char>> map(n,vector<char>(m));
    vector<vector<vector<int>>> transmit(26);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]=='@')
                start={i,j};
            if('A'<=map[i][j] && map[i][j]<='Z')
                transmit[map[i][j]-'A'].push_back({i,j});
            
        }
    }
    cout<<bfs(start,map,transmit)<<'\n';
    return 0;
}