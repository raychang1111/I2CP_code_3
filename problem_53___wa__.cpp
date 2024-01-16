// https://www.luogu.com.cn/problem/P1080       //大數  待處理  未完
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first*a.second < b.first*b.second;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    pair<int,int> curr;
    vector<pair<int,int>> arr(n);
    cin>>curr.first>>curr.second;
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++){
        ans=max(ans,curr.first/arr[i].second);
        curr.first*=arr[i].first;
    }
    cout<<ans<<endl;
    return 0;
}