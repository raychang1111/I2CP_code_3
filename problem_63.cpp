// https://vjudge.net/problem/UVA-12428
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        long long l=0,r=m,mid,ans;
        while(l<=r){
            mid=(l+r)/2;
            if(mid<=n && mid<=m && m-mid<=(n-mid)*(n-mid-1)/2){
                l=mid+1;
                ans=mid;
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}