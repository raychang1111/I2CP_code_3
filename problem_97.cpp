// https://www.luogu.com.cn/problem/P2196
#include <bits/stdc++.h>
using namespace std;
void print_path(int i,vector<int> &prev){
    if(prev[i]!=i)
        print_path(prev[i],prev);
    cout<<i+1<<' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,temp,pos=-1,ans=0;
    cin>>n;
    vector<int> arr(n);
    vector<vector<bool>> edge(n,vector<bool>(n));
    vector<int> dp(n);
    vector<int> prev(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        prev[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cin>>temp;
            edge[i][j]=temp;
        }
    }
    dp[0]=arr[0];
    ans=dp[0];
    pos=0;
    for(int i=1;i<n;i++){
        dp[i]=arr[i];
        for(int j=0;j<i;j++){
            if(edge[j][i] && dp[i]<dp[j]+arr[i]){
                dp[i]=dp[j]+arr[i];
                prev[i]=j;
            }
        }
        if(ans<dp[i]){
            ans=dp[i];
            pos=i;
        }
    }    
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;
    print_path(pos,prev);
    cout<<'\n';
    cout<<ans<<'\n';
    return 0;
}
