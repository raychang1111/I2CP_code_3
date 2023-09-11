// https://www.luogu.com.cn/problem/P1464
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll W(ll a,ll b,ll c,vector<vector<vector<ll>>> &dp){
    if(a<=0 || b<=0 || c<=0)
        return 1;
    if(a>20 || b>20 || c>20)
        return dp[20][20][20];
    return dp[a][b][c];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll a,b,c;
    vector<vector<vector<ll>>> dp(20+1,vector<vector<ll>>(20+1,vector<ll>(20+1,1)));
    for(a=1;a<=20;a++){
        for(b=1;b<=20;b++){
            for(c=1;c<=20;c++){
                if(a<b && b<c)
                    dp[a][b][c]=dp[a][b][c-1]+dp[a][b-1][c-1]-dp[a][b-1][c];
                else
                    dp[a][b][c]=dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
            }
        }
    }
    while(cin>>a>>b>>c && (a!=-1 || b!=-1 || c!=-1)){
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<W(a,b,c,dp)<<endl;
    }
    return 0;
}