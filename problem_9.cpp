// https://www.luogu.com.cn/problem/P1182
#include <iostream>
#include <vector>
using namespace std;
bool check(int mid,vector<int> &arr,int k){
    int total=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>mid)
            return false;
        if(total+arr[i]>mid){
            total=arr[i];
            k--;
        }
        else    
            total+=arr[i];
    }
    return k>0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,arr,m)){
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}