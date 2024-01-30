// https://www.luogu.com.cn/problem/P1090
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    long long ans=0,temp;
    cin>>n;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=0;i<n;i++){
        cin>>temp;
        pq.push(temp);
    }
    while(pq.size()>=2){
        temp=pq.top();pq.pop();
        temp+=pq.top();pq.pop();
        pq.push(temp);
        ans+=temp;
    }
    cout<<ans<<endl;
    return 0;
}
