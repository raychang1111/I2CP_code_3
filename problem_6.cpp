// https://www.luogu.com.cn/problem/P2440
#include <vector>
#include <iostream>
using namespace std;
bool check(int m,vector<int> &arr,int k){
    if(m==0)
        return true;
    for(int i=0;k>0 && i<arr.size();i++)
        k-=(arr[i]/m);
    return k<=0;
}
signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    int l=0,r=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        r=max(r,arr[i]);
    }
    while(l<=r){
        int m=(l+r)/2;
        if(check(m,arr,k)){
            l=m+1;
            ans=m;
        }
        else
            r=m-1;
    }
    cout<<ans<<endl;
    return 0;
}