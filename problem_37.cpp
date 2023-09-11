// https://www.luogu.com.cn/problem/P1010
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void print(int n,int i,vector<string> &dp){
    if(n==0)
        return ;
    print(n>>1,i+1,dp);
    if(n&1){
        if((n>>1)!=0)
            cout<<'+';
        cout<<dp[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<string> dp(16);
    dp[0]="2(0)";
    dp[1]="2";
    dp[2]="2(2)";
    for(int i=3;i<16;i++){ 
        for(int j=i,count=0;j!=0;j>>=1,count++){
            if(j&1)
                dp[i]=dp[i].empty()?  (dp[count]):(dp[count]+"+"+dp[i]);
        }
        dp[i]="2("+dp[i]+")";
    }
    print(n,0,dp);
    return 0;
}