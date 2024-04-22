// https://www.luogu.com.cn/problem/P3385
#include <bits/stdc++.h>
using namespace std;
signed main(){
    int T,n,m,a,b,c;
    cin>>T;
    while(T--){
        bool flag=false;
        cin>>n>>m;
        vector<vector<int>> edge;
        while(m--){
            cin>>a>>b>>c;
            a--;
            b--;
            if(c>=0){
                edge.push_back({a,b,c});
                edge.push_back({b,a,c});
            }
            else
                edge.push_back({a,b,c});
        }
        vector<int> ans(n,1e9);
        ans[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<edge.size();j++){
                if(ans[edge[j][0]]!=1e9)
                    ans[edge[j][1]]=min(ans[edge[j][1]],ans[edge[j][0]]+edge[j][2]);
            }
        }
        for(int j=0;j<edge.size();j++){
            if(ans[edge[j][0]]==1e9 || ans[edge[j][1]]==1e9)
                continue;
            if(ans[edge[j][0]]+edge[j][2]<ans[edge[j][1]]){
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
/* -----------SPFA--------------------------------
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n,m,u,v,w;
    cin>>t;
    while(t--){
        bool ans=false;
        cin>>n>>m;
        vector<vector<pair<int,int>>> link(n);
        while(m--){
            cin>>u>>v>>w;
            u--;
            v--;
            if(w>=0)
                link[v].push_back({u,w});        
            link[u].push_back({v,w});
        }
        vector<int> date(n,-1);
        vector<int> dis(n,INT_MAX);
        queue<int> Q;
        vector<bool> in_Q(n,false);
        date[0]=0;
        dis[0]=0;
        Q.push(0);
        in_Q[0]=true;
        while(!Q.empty()){
            int node=Q.front();
            Q.pop();
            in_Q[node]=false;
            if(date[node]>n){
                ans=true;
                break;
            }
            for(int i=0;i<link[node].size();i++){
                if(dis[link[node][i].first]>dis[node]+link[node][i].second){
                    dis[link[node][i].first]=dis[node]+link[node][i].second;
                    date[link[node][i].first]=date[node]+1;
                    if(!in_Q[link[node][i].first]){
                        in_Q[link[node][i].first]=true;
                        Q.push(link[node][i].first);
                    }
                }
            }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
//------------------------------------------------*/