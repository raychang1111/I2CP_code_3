// https://vjudge.net/problem/UVA-10684 (最大連續區間和)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==0)
            break;
        vector<int> arr(n);
        vector<int> dp(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        dp[0]=arr[0];
        int ans=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+arr[i],arr[i]);
            ans=max(ans,dp[i]);
        }
        if(ans<=0)
            cout<<"Losing streak.\n";
        else
            cout<<"The maximum winning streak is "<<ans<<".\n";
    }
    return 0;
}