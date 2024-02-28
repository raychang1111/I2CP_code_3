// https://www.luogu.com.cn/problem/P1540
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,k,ans=0;
    cin>>n>>m;
    queue<int> Q;
    set<int> S;
    for(int i=0;i<m;i++){
        cin>>k;
        if(!S.count(k)){
            if(Q.size()==n){
                S.erase(Q.front());
                Q.pop();
            }
            Q.push(k);
            S.insert(k);
            // for(set<int>::iterator itr=S.begin();itr!=S.end();itr++)
            //     cout<<*itr<<' ';
            // cout<<'\n';
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}