// https://www.luogu.com.cn/problem/P1803
#include <bits/stdc++.h>
using namespace std;
bool cmp_self(vector<int> &a,vector<int> &b){
    return a[1]<b[1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans=0,k=0;
    cin>>n;
    vector<vector<int>> schedule(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>schedule[i][0]>>schedule[i][1];
    sort(schedule.begin(),schedule.end(),cmp_self);
    for(int i=0;i<n;i++){
        if(k<=schedule[i][0]){
            k=schedule[i][1];
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}