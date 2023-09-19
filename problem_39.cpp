// https://www.luogu.com.cn/problem/P1498
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int pow_self(int a,int b){
    int res=1;
    while(b){
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<vector<char>> dp(pow_self(2,n),vector<char>(pow_self(2,n+1),' '));
    dp[0][0]=' ';
    dp[0][1]='/';
    dp[0][2]='\\';
    dp[1][0]='/';
    dp[1][1]='_';
    dp[1][2]='_';
    dp[1][3]='\\';
    for(int i=1;i<n;i++){
        int temp=pow_self(2,i);
        for(int j=0;j<temp;j++){
            for(int k=0;k<temp*2;k++){
                dp[j+temp][k]=dp[j][k];
                dp[j][k]=' ';
            }
        }
        for(int j=0;j<temp;j++){
            for(int k=0;k<temp*2;k++){
                dp[j+temp][k+temp*2]=dp[j+temp][k];
                dp[j][k+temp]=dp[j+temp][k];
            }
        }
    }
    for(int i=0;i<pow_self(2,n);i++){
        for(int j=0;j<pow_self(2,n+1);j++)
            cout<<dp[i][j];
        cout<<endl;
    }
    return 0;
}