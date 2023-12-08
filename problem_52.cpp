// https://www.luogu.com.cn/problem/P1223
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}
int main(){
    int n;
    double temp=0,ans=0;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
        arr[i].first=i+1;
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<n;i++){
        ans+=temp;
        temp+=arr[i].second;
        cout<<arr[i].first<<' ';
    }
    cout<<endl;
    cout<<fixed<<setprecision(2)<<ans/n<<endl;
    return 0;
}