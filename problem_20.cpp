// https://www.luogu.com.cn/problem/P3654
#include <iostream>
#include <vector>
using namespace std;
int count(int i,int j,vector<vector<char>> &map,const int &k){
    if(k==1)
        return map[i][j]=='.'? 1:0;
    bool tag=false;
    int res=0;
    for(int x=i;!tag && x<i+k;x++)
        tag=(x>=map.size() || map[x][j]=='#');
    if(!tag)
        res++;
    tag=false;
    for(int y=j;!tag && y<j+k;y++)
        tag=(y>=map[0].size() || map[i][y]=='#');
    if(!tag)
        res++;
    return res;
}
int main(){
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    vector<vector<char>> map(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>map[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans+=count(i,j,map,k);
    cout<<ans<<endl;
    return 0;
}