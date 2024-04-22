// https://www.luogu.com.cn/problem/P1280 (好題)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> work(k);
    for(int i=0;i<k;i++){
        cin>>work[i].first>>work[i].second;
        work[i].first--;
    }
    sort(work.begin(),work.end());
    vector<int> dp(n+1,0);
    for(int i=n-1,j=k-1;i>=0;i--){
        if(j<0){
            dp[i]=dp[i+1]+1;
        }
        else if(i==work[j].first){
            while(j>=0 && i==work[j].first){
                dp[i]=max(dp[i],dp[i+work[j].second]);
                j--;
            }
        }
        else{
            dp[i]=dp[i+1]+1;
        }
    }
    cout<<dp[0]<<'\n';
    return 0;
}








































// dp[i]表示i~n的最大空閒時間 從後面pd回去