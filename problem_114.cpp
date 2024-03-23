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