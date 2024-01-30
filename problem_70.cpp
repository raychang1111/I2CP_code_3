// https://www.luogu.com.cn/problem/P1616   �L���I�]
#include <bits/stdc++.h>
using namespace std;
void s1(){                  //���u�ƫe
    long long t,m;
    cin>>t>>m;
    vector<pair<long long,long long>> herbal_medicine(m);   //first:�ɶ� second:����
    vector<vector<long long>> dp(m,vector<long long>(t+1,0)); //dp[i][j] �ei�د��� �bj�ɶ��U���̤j�į��Ļ���
    for(long long i=0;i<m;i++)
        cin>>herbal_medicine[i].first>>herbal_medicine[i].second;
    for(long long i=herbal_medicine[0].first;i<=t;i++)
        dp[0][i]=dp[0][i-herbal_medicine[0].first]+herbal_medicine[0].second;
    for(long long i=1;i<m;i++){
        for(long long j=1;j<=t;j++){
            if(j<herbal_medicine[i].first)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-herbal_medicine[i].first]+herbal_medicine[i].second);
        }
    }
    cout<<dp[m-1][t]<<endl;
}
void s2(){
    int t,m;
    cin>>t>>m;
    vector<pair<long long,long long>> herbal_medicine(m);   //first:�ɶ� second:����
    vector<long long> dp(t+1,0); //dp[i][j] �ei�د��� �bj�ɶ��U���̤j�į��Ļ��� + �ϥκu�ʼƲ�
    for(int i=0;i<m;i++)
        cin>>herbal_medicine[i].first>>herbal_medicine[i].second;
    for(int i=0;i<m;i++){
        for(int j=herbal_medicine[i].first;j<=t;j++){
            dp[j]=max(dp[j],dp[j-herbal_medicine[i].first]+herbal_medicine[i].second);
        }
    }
    cout<<dp[t]<<endl;
}
int main(){
    s2();
    return 0;
}
