// https://www.luogu.com.cn/problem/P4568       (分層建圖) 完全沒想到
#include <bits/stdc++.h>
using namespace std;
class cmp_self{
public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
};
int main(){
    int n,m,k,s,t,a,b,c;
    cin>>n>>m>>k;
    cin>>s>>t;
    k++;
    vector<vector<pair<int,int>>> link(n*k);
    vector<bool> run(n*k,false);
    vector<int> ans(n*k,INT_MAX);
    while(m--){
        cin>>a>>b>>c;
        link[a].push_back({b,c});
        link[b].push_back({a,c});
        for(int i=1;i<k;i++){
            link[a+n*(i-1)].push_back({b+n*i,0});
            link[b+n*(i-1)].push_back({a+n*i,0});
            link[a+n*i].push_back({b+n*i,c});
            link[b+n*i].push_back({a+n*i,c});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp_self> pq;
    pq.push({s,0});
    ans[s]=0;
    while(!pq.empty()){
        pair<int,int> node=pq.top();
        pq.pop();
        if(run[node.first])
            continue;
        run[node.first]=true;
        for(int i=0;i<link[node.first].size();i++){
            if(!run[link[node.first][i].first]){
                ans[link[node.first][i].first]=min(ans[link[node.first][i].first],ans[node.first]+link[node.first][i].second);
                pq.push({link[node.first][i].first,ans[link[node.first][i].first]});
            }
        }
    }
    // for(int i=0;i<k;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<ans[i*n+j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    int res=INT_MAX;
    for(int i=0;i<k;i++)
        res=min(ans[i*n+t],res);
    cout<<res<<'\n';
    return 0;
}