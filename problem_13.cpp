// https://www.luogu.com.cn/problem/P2089
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void Backtracking(int n,vector<vector<int>> &ans,vector<int> &path){
    if(path.size()==10){
        if(n==0)
            ans.push_back(path);
        return ;
    }
    for(int i=1;i<=3;i++){
        path.push_back(i);
        Backtracking(n-i,ans,path);
        path.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if(n<10 || n>30)
        cout<<0<<endl;
    else{
        vector<vector<int>> ans;
        vector<int> path;
        Backtracking(n,ans,path);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            for(int aa:ans[i])
                cout<<aa<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}