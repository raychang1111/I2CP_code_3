// https://www.luogu.com.cn/problem/P5911   ����DP
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,W;
    cin>>W>>n;
    vector<pair<int,int>> people(n);    // first:t second:w
    vector<int> w(1<<n);
    vector<int> t(1<<n);
    vector<int> dp(1<<n,1e8);
    for(int i=0;i<n;i++)
        cin>>people[i].first>>people[i].second;
    for(int i=0;i<(1<<n);i++){
        w[i]=0;
        t[i]=0;
        for(int j=0;j<n;j++){
            if(i>>j&1){
                w[i]+=people[j].second;
                t[i]=max(t[i],people[j].first);
            }
        }
    }
    dp[0]=0;
    for(int i=0;i<(1<<n);i++){          
        for(int j=i;;j=(j-1)&i){        //�a�|i���l���X�g�k  ex:01010 �l���X��:01000 00010
            if(w[i^j]<=W)
                dp[i]=min(dp[i],dp[j]+t[i^j]);
            if(!j)
                break;
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}
/*       �]�ӬO�諸(�q?) ���Ĳv�t���z
#include <bits/stdc++.h>
#define int long long
#define _0 first
#define _1 second
using namespace std;
signed main(){
    int w,n,ans=LONG_LONG_MAX/2;
    cin>>w>>n;
    vector<pair<int,int>> people(n);       //  ?? ���q 
    vector<vector<vector<pair<int,int>>>> dp(n,vector<vector<pair<int,int>>>(1<<n,vector<pair<int,int>>(n+1,{LONG_LONG_MAX/2,0}))); 
    //dp[i][j][k] 0~i�� �M �ثe�̫�@�լ�j���A �M �w���Lk�H  ���̤p�L���ɶ�
    // dp[i][j][k] 0~i�� �M �ثe�̫�@�լ�j���A �M �w���Lk�H ���w�L�����A
    vector<vector<int>> state;    // 0:���A 1:�����A1���Ӽ� 2:�����A�U���L���ɶ�  
    for(int i=0;i<n;i++)
        cin>>people[i]._0>>people[i]._1;
    for(int i=0;i<(1<<n);i++){
        int count=0,weight=w,time=0;
        for(int j=0;j<n && 0<=weight;j++){
            if(i>>j&1){
                time=max(time,people[j]._0);
                weight-=people[j]._1;
                count++;
            }
        }
        if(0<=weight){
            state.push_back({i,count,time});
        }
    }
    for(int i=0;i<state.size();i++){
        dp[0][state[i][0]][state[i][1]]._0=state[i][2];
        dp[0][state[i][0]][state[i][1]]._1=state[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<state.size();j++){
            // state[j][0]
            for(int k=1;k<=n;k++){
                if(k<state[j][1]) continue;
                for(int x=0;x<state.size();x++){
                    if(x==k)continue;
                    if((dp[i-1][state[x][0]][k-state[j][1]]._1&state[j][0]) !=0) continue;
                    if(dp[i][state[j][0]][k]._0<dp[i-1][state[x][0]][k-state[j][1]]._0+state[j][2]) continue;
                    // cout<<((dp[i-1][state[x][0]][k-state[j][1]]._1&state[j][0]) !=0)<<' ';
                    // cout<<dp[i-1][state[x][0]][k-state[j][1]]._1<<' '<<state[j][0]<<' ';
                    dp[i][state[j][0]][k]._0=dp[i-1][state[x][0]][k-state[j][1]]._0+state[j][2];
                    dp[i][state[j][0]][k]._1=dp[i-1][state[x][0]][k-state[j][1]]._1|state[j][0];
                    // cout<<dp[i][state[j][0]][k]._1<<endl;
                }
                if(k==n)
                    ans=min(ans,dp[i][state[j][0]][k]._0);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/