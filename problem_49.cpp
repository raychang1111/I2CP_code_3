// https://vjudge.net/problem/UVA-1193                  //白癡題目 貪心
#include <bits/stdc++.h>    
#define EPS 1e-7
#define long long int
#define endl '\n'
using namespace std;
bool cmp(pair<double,double> &a,pair<double,double> &b){
    return a.second<b.second;                           //重點
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,r,x,y;
    double d;
    for(int i=1;cin>>n>>r && n!=0;i++){
        bool flag=false;
        int ans=1;
        vector<pair<double,double>> arr(n);
        for(int j=0;j<n;j++){
            cin>>x>>y;
            if(r<y)
                flag=true;
            else{
                d=sqrt(r*r-y*y);
                arr[j].first=(double)x-d;
                arr[j].second=(double)x+d;
            }
        }
        if(flag){
            cout<<"Case "<<i<<": "<<-1<<endl;
            continue;
        }
        sort(arr.begin(),arr.end(),cmp);
        for(int j=1,d=arr[0].second;j<n;j++){
            if(d-arr[j].first<-EPS){
                d=arr[j].second;
                ans++;
            }
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}