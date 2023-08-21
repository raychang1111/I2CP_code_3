// https://www.luogu.com.cn/problem/P3743
#include <bits/stdc++.h>
#define EPS 1e-6
#define int long long
using namespace std;
bool check(double mid,vector<pair<int,int>> &arr,double p){
    double Charge=mid*p;
    for(int i=0;Charge>-EPS && i<arr.size();i++){
        if(arr[i].second-(arr[i].first*mid)<0)
            Charge+=(arr[i].second-(arr[i].first*mid));
    }
    return Charge>-EPS;
}
signed main(){
    int n,p;
    long long total=0;
    cin>>n>>p;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        total+=arr[i].first;
    }
    if(total<=p){
        cout<<"-1"<<endl;
        return 0;
    }
    double l=0,r=1e10,ans=-1;
    while(l<=r){
        double mid=(l+r)/2;
        if(check(mid,arr,p)){
            l=mid+EPS;
            ans=mid;
        }
        else    
            r=mid-EPS;
    }
    cout<<ans<<endl;
    return 0;
}