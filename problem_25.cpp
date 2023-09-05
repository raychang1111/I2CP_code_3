// https://www.luogu.com.cn/problem/P2036
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dfs(int acid,int bitter,int i,vector<pair<int,int>> &condiment){
    if(i==condiment.size())
        return abs(acid-bitter);
    return min(dfs(acid*condiment[i].first,bitter+condiment[i].second,i+1,condiment),dfs(acid,bitter,i+1,condiment));
}
signed main(){
    int n,ans=INT_MAX;
    cin>>n;
    vector<pair<int,int>> condiment(n);
    for(int i=0;i<n;i++)
        cin>>condiment[i].first>>condiment[i].second;
    for(int i=0;i<n;i++)
        ans=min(ans,dfs(condiment[i].first,condiment[i].second,i+1,condiment));
    cout<<ans<<endl;
    return 0;
}