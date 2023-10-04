// https://www.luogu.com.cn/problem/P2367
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){                         //®t¤ÀÃD
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,p,curr,prev=0;
    cin>>n>>p;
    vector<int> dis(n);
    for(int i=0;i<n;i++){
        cin>>curr;
        dis[i]=curr-prev;
        prev=curr;
    }
    int l,r,a;
    for(int i=0;i<p;i++){
        cin>>l>>r>>a;
        if(r<n){
            dis[l-1]+=a;
            dis[r]-=a;
        }
        else    
            dis[l-1]+=a;
    }
    int a_sum=0,ans=INT_MAX;
    for(int i=0;i<n;i++){
        a_sum+=dis[i];
        ans=min(ans,a_sum);
    }
    cout<<ans<<endl;
    return 0;
}