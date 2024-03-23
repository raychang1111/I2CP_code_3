// https://vjudge.net/problem/UVA-12911
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,t;
    while(cin>>n){
        cin>>t;
        vector<int> arr(n);
        map<int,int> M;
        int ans=0;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int mid=n/2,count;
        // 0~mid
        // mid+1~n-1
        // (mid+1)
        // (n-mid-1)
        for(int i=0;i<(1<<mid+1);i++){
            count=0;
            for(int j=0;j<mid+1;j++){
                if(i>>j&1){
                    count+=arr[j];
                }
            }
            M[count]++;
        }
        for(int i=0;i<(1<<n-mid-1);i++){
            count=0;
            for(int j=0;j<n-mid-1;j++){
                if(i>>j&1){
                    count+=arr[mid+1+j];
                }
            }
            if(M.find(t-count)!=M.end())
                ans+=M[t-count];
        }
        if(t==0)
            ans--;
        cout<<ans<<'\n';
    }
    return 0;
}