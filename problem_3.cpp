// https://www.luogu.com.cn/problem/P1873
#include <iostream>
#include <vector>
#define  endl '\n'
using namespace std;
bool check(int m,vector<long long> &arr,int t){
    for(int i=0; t>=0 && i<arr.size();i++){
        t-=max((long long)0,arr[i]-m);
    }
    return !(t>0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    long long t;
    cin>>n>>t;
    vector<long long> arr(n);
    long long l=0,r=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        r=max(arr[i],r);
    }
    long long ans=0;
    while(l<=r){
        long long m=(l+r)/2;
        if(check(m,arr,t)){
            l=m+1;
            ans=m;
        }
        else
            r=m-1;
    }
    cout<<ans<<endl;
    
    return 0;
}