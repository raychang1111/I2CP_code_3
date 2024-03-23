// https://www.luogu.com.cn/problem/P4779           dijkstra (¼Ð·ÇÃD)
#include <bits/stdc++.h>
using namespace std;
class cmp_self{
public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,s,a,b,c;
    cin>>n>>m>>s;
    s--;
    vector<vector<pair<int,int>>> link(n); //i-j w
    while(m--){
        cin>>a>>b>>c;
        a--;
        b--;
        link[a].push_back({b,c});
    }
    vector<int> ans(n,INT_MAX);
    vector<bool> run(n,false);
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
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}