#include <bits/stdc++.h>
using namespace std;
int dfs(int i,vector<vector<int>> &link,vector<vector<int>> &dp){
    int sum0=0,sum1=0;
    for(int j=0;j<link[i].size();j++){
        dfs(link[i][j],link,dp);
        sum0+=min(dp[link[i][j]][0],dp[link[i][j]][1]); //i點一定會選 故子root可選可不選
        sum1+=dp[link[i][j]][1];                        //i點不會選 故子root一定要選
    }
    dp[i][0]=sum1;
    dp[i][1]=sum0+1;
    return min(dp[i][0],dp[i][1]);
}
int main(){
    int n,x,m,y;
    string s;
    while(cin>>n){
        vector<vector<int>> link(n);
        vector<bool> is_root(n,true);
        for(int k=0;k<n;k++){
            cin>>s;
            bool flag=false;
            x=0;
            m=0;
            for(int i=0;i<s.size();i++){
                if('0'<=s[i] && s[i]<='9'){
                    if(!flag)
                        x=x*10+(s[i]-'0');
                    else
                        m=m*10+(s[i]-'0');
                }
                else
                    flag=true;
            }
            for(int i=0;i<m;i++){
                cin>>y;
                link[x].push_back(y);
                is_root[y]=false;
            }
        }
        int ans=0;
        vector<vector<int>> dp(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            if(is_root[i]){
                // cout<<i<<'\n';
                ans+=dfs(i,link,dp);
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}