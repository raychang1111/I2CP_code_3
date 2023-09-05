// https://www.luogu.com.cn/problem/P1028
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n,1);
    for(int i=1;i<=n;i++){
        for(int j=i/2;j>=1;j--)
            dp[i-1]+=dp[j-1];
    }
    cout<<dp[n-1]<<endl;
    return 0;
}