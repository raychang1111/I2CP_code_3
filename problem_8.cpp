// https://www.luogu.com.cn/problem/P3853
#include <iostream>
#include <vector>
using namespace std;
bool check(int mid,vector<int> &arr,int k){
    if(mid==0)
        return false;
    for(int i=1;k>=0 && i<arr.size();i++){
        if(arr[i]-arr[i-1]>mid)
            k-=((arr[i]-arr[i-1]-1)/mid);
    }
    return k>=0;
}
int main(){
    int L,N,K;
    cin>>L>>N>>K;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        cin>>arr[i];
    int l=0,r=L,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,arr,K)){
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}