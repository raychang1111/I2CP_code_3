// https://www.luogu.com.cn/problem/P2678
#include <iostream>
#include <vector>
using namespace std;
bool check(int mid,vector<int> &arr,int l,int loss){
    int prev=0;
    for(int i=0;loss >= 0 && i<arr.size();i++){
        if(arr[i]-prev < mid)
            loss--;
        else
            prev=arr[i];
    }
    if(l-prev < mid)
        loss--;
    return loss>=0;
}
int main(){
    int l,n,m;
    cin>>l>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int L=0,R=l,ans=0;
    while(L<=R){
        int mid=(L+R)/2;
        if(check(mid,arr,l,m)){
            L=mid+1;
            ans=mid;
        }
        else
            R=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}