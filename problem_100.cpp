// https://www.luogu.com.cn/problem/P1115
#include<bits/stdc++.h>
using namespace std;
int D_and_C(int l,int r,vector<int> &arr){
    if(l==r)
        return max(arr[l],0);
    int mid=(l+r)/2,res;
    res=D_and_C(l,mid,arr);
    res=max(res,D_and_C(mid+1,r,arr));
    int temp=0,ls=0,rs=0;
    for(int i=mid;i>=l;i--){
        temp+=arr[i];
        ls=max(ls,temp);
    }
    temp=0;
    for(int i=mid+1;i<=r;i++){
        temp+=arr[i];
        rs=max(rs,temp);
    }
    return max(res,ls+rs);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans=-1e5;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ans=max(ans,arr[i]);
    }
    if(ans<0)
        cout<<ans;
    else
        cout<<D_and_C(0,n-1,arr);
    cout<<'\n';
    return 0;
}