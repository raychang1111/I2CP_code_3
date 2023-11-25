// https://zerojudge.tw/ShowProblem?problemid=f493 
#include <bits/stdc++.h>
using namespace std;
int dfs(int i,int j,vector<vector<bool>> &map){
    int res=1;
    map[i][j]=false;
    if(i+1<map.size() && map[i+1][j])
        res+=dfs(i+1,j,map);
    if(j+1<map[0].size() && map[i][j+1])
        res+=dfs(i,j+1,map);
    if(0<=i-1 && map[i-1][j])
        res+=dfs(i-1,j,map);
    if(0<=j-1 && map[i][j-1])
        res+=dfs(i,j-1,map);
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    char c;
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> map(n,vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            map[i][j]=(c=='W');
        }
    }
    int Max_c=INT_MIN,Min_c=INT_MAX,count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]){
                int temp=dfs(i,j,map);
                count++;
                Min_c=min(Min_c,temp);
                Max_c=max(Max_c,temp);
            }
        }
    }
    if(count==0)                        //µL¤ôâp±¡ªp
        Max_c=Min_c=0;
    cout<<Max_c<<' '<<Min_c<<' '<<count<<'\n';
    return 0;
}