// https://vjudge.net/problem/UVA-10672
#include <bits/stdc++.h> 
#define endl '\n'
using namespace std;
int D_and_c(int i,vector<vector<int>> &link,vector<int> &property){         //¤Àªv
    int res=0;
    for(int j=0;j<link[i].size();j++){
        res+=D_and_c(link[i][j],link,property);
        while(property[link[i][j]]<1){
            property[link[i][j]]++;
            property[i]--;
            res++;
        }
        while(property[link[i][j]]>1){
            property[link[i][j]]--;
            property[i]++;
            res++;
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans,a,b,c;
    while(cin>>n && n!=0){
        ans=0;
        vector<bool> roots(n,true);    //node
        vector<vector<int>> link(n);
        vector<int> property(n);
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            a--;
            property[a]=b;
            for(int j=0;j<c;j++){
                cin>>b;
                b--;
                link[a].push_back(b);
                roots[b]=false;
            }
        }
        for(int i=0;i<roots.size();i++){
            if(roots[i])
                ans+=D_and_c(i,link,property);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
#include <bits/stdc++.h>                    //WA
#define long long int
#define endl '\n'
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int BFS(int node,vector<vector<int>> &link,vector<int> &property){
    int res=0,order=0;
    queue<int> Q;
    vector<bool> run(link.size(),false);
    Q.push(node);
    run[node]=true;
    while(!Q.empty() && property[node]>1){
        int n=Q.size();
        for(int i=0;i<n && property[node]>1;i++){
            for(int j=0;j<link[Q.front()].size();j++){
                if(!run[link[Q.front()][j]]){
                    Q.push(link[Q.front()][j]);
                    run[link[Q.front()][j]]=true;
                }
            }
            if(property[Q.front()]==0){
                property[node]--;
                property[Q.front()]++;
                res+=order;
            }
            Q.pop();
        }
        order++;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans,a,b,c;
    while(cin>>n && n!=0){
        ans=0;
        vector<int> BFS_order;    //node
        vector<vector<int>> link(n);
        vector<int> property(n);
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            a--;
            property[a]=b;
            if(b>1)
                BFS_order.push_back(a);
            for(int j=0;j<c;j++){
                cin>>b;
                b--;
                link[a].push_back(b);
                link[b].push_back(a);
            }
        }
        sort(BFS_order.begin(),BFS_order.end(),cmp);            //???????????? ?????
        for(int i=0;i<BFS_order.size();i++)
            ans+=BFS(BFS_order[i],link,property);
        cout<<ans<<endl;
    }
    return 0;
}
*/