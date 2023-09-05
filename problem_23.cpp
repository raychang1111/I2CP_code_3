// https://www.luogu.com.cn/problem/P3799
#include <bits/stdc++.h>
// #define int long long
const int mod=1e9+7;
using namespace std;
int two_sum(int i,vector<int> &times){
    int res=0;
    for(int j=i-1;j>i/2;j--)
        res=(res+times[i-j]*times[j]%mod)%mod;
    if(i%2==0)
        res=(res+times[i/2]*(times[i/2]-1)/2)%mod;
    return res;
}
signed main(){
    int n,temp,ans=0;
    cin>>n;
    vector<int> times(5*1000+1,0);
    for(int i=0;i<n;i++){
        cin>>temp;
        times[temp]++;
    }
    for(int i=times.size();i>0;i--){
        if(times[i]>=2){
            int a=two_sum(i,times);
            ans+=(a*((times[i]*(times[i]-1)/2)%mod))%mod;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}