// https://www.luogu.com.cn/problem/P2240
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(pair<double,double> a, pair<double,double> b){
    return a.second/a.first>b.second/b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,t;
    double ans=0;
    cin>>n>>t;
    vector<pair<double,double>> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<arr.size();i++){
        if(arr[i].first>t){
            ans+=(arr[i].second/arr[i].first)*t;
            break;
        }
        else{
            ans+=arr[i].second;
            t-=arr[i].first;
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}