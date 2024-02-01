// https://www.luogu.com.cn/problem/P2404
#include <bits/stdc++.h>
using namespace std;
void dfs(int i,int n,string &path){
    if(n==0){
        if(path.size()==2)
            return ;
        for(int j=1;j<path.size();j++)
            cout<<path[j];
        cout<<'\n';
        return ;
    }
    for(int j=i;j<=n;j++){
        path.push_back('+');
        path.push_back(j+'0');
        dfs(j,n-j,path);
        path.pop_back();
        path.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    string path;
    cin>>n;
    dfs(1,n,path);
    return 0;
}