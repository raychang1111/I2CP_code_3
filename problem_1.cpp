// https://www.luogu.com.cn/problem/P2249
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    while(m--){
        int t,ans=INT_MAX;
        cin>>t;
        int l=0,r=arr.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(arr[m]==t){
                r=m-1;
                ans=min(ans,m+1);
            }
            else if(arr[m]>t)
                r=m-1;
            else
                l=m+1;
        }
        if(ans==INT_MAX)
            cout<<-1<<' ';
        else
            cout<<ans<<' ';
    }
    cout<<endl;
    return 0;
}