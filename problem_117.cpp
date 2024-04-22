// https://www.luogu.com.cn/problem/P1194
#include <bits/stdc++.h>
using namespace std;
bool cmp_self(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
void init_disjoint_set(vector<int> &disjoint_set){
    for(int i=0;i<disjoint_set.size();i++)
        disjoint_set[i]=i;
}
int find_set(int x,vector<int> &disjoint_set){
    if(disjoint_set[x]==x)  
        return x;
    else
        return disjoint_set[x]=find_set(disjoint_set[x],disjoint_set);
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int a,b,c,x,y;
    cin>>a>>b;
    vector<vector<int>> edge;
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++){
            cin>>c;
            if(i<j && c!=0 &&c<a)
                edge.push_back({i,j,c});
        }
    }
    sort(edge.begin(),edge.end(),cmp_self);
    vector<int> disjoint_set(b);
    int ans=0;
    init_disjoint_set(disjoint_set);
    for(int i=0;i<edge.size();i++){
        x=find_set(edge[i][0],disjoint_set);
        y=find_set(edge[i][1],disjoint_set);
        if(x!=y){
            disjoint_set[y]=x;
            ans+=edge[i][2];
        }
    }
    vector<bool> flag(b,false);
    for(int i=0;i<b;i++){
        x=find_set(i,disjoint_set);
        if(!flag[x]){
            flag[x]=true;
            ans+=a;
        }
    }
    cout<<ans<<'\n';
    return 0;
}