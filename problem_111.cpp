// https://www.luogu.com.cn/problem/P1496   •’√®√D
#include<bits/stdc++.h>
using namespace std;
bool cmp_self(pair<int,int> &a,pair<int,int> &b){
    return a.first<b.first;
}
int main(){
    int n,end=INT_MIN,ans=0;
    cin>>n;
    vector<pair<int,int>> data(n);
    for(int i=0;i<n;i++)
        cin>>data[i].first>>data[i].second;
    sort(data.begin(),data.end(),cmp_self);
    for(int i=0;i<data.size();i++){
        if(end<data[i].first){
            ans+=(data[i].second-data[i].first);
            end=data[i].second;
        }
        else{
            if(data[i].second>end){
                ans+=(data[i].second-end);
                end=data[i].second;
            }
        }
        // cout<<ans<<' ';
    }
    cout<<ans<<'\n';
    return 0;
}