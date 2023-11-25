// 動態規劃題型
#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
void DP_1(){        //  https://zerojudge.tw/ShowProblem?problemid=d133         零錢問題
    int n;
    vector<int> cent={1,5,10,25,50};
    while(cin>>n){
        vector<long long> dp(n+1,1);
        for(int i=1;i<cent.size();i++){
            for(int j=cent[i];j<=n;j++){
                dp[j]+=dp[j-cent[i]];
            }
        }
        if(dp[n]==1){
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        }
        else{
            cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change."<<endl;
        }
    }   
}
void DP_2(){        //  https://zerojudge.tw/ShowProblem?problemid=b131         01背包
    int property,n;
    cin>>property>>n;
    vector<int> v(n);
    vector<int> w(n);
    vector<vector<int>> dp(n,vector<int>(property+1,0));
    for(int i=0;i<n;i++)
        cin>>v[i]>>w[i];
    for(int i=v[0];i<=property;i++)
        dp[0][i]=v[0]*w[0];
    for(int i=1;i<n;i++)
        for(int j=0;j<=property;j++)
            dp[i][j]=j>v[i]? max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*w[i]):dp[i-1][j];
    cout<<dp[n-1][property]<<endl;
}
void DP_3_print(int i,vector<long long> &arr,vector<long long> &dp,vector<long long> &prev){
    if(i==prev[i]){
        cout<<arr[i]<<endl;
        return ;
    }
    DP_3_print(prev[i],arr,dp,prev);
    if(dp[i]!=dp[prev[i]])
        cout<<arr[i]<<endl;
    
}
void DP_3(){        // https://zerojudge.tw/ShowProblem?problemid=d242      LIS O(n^2)
    int n,temp;
    queue<long long> Q;
    while(cin>>temp){
        Q.push(temp);
        n++;
    }
    vector<long long> arr(n,0);
    vector<long long> dp(n,0);
    vector<long long> prev(n,0);
    for(int i=0;i<n;i++){
        arr[i]=Q.front();
        dp[i]=1;
        prev[i]=i;
        Q.pop();
    }
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--)
            if(arr[j]<arr[i]){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
    }
    int ans=0;
    for(int i=1;i<n;i++)
        ans=dp[ans]<=dp[i]? i:ans;
    cout<<dp[ans]<<endl;
    cout<<'-'<<endl;
    DP_3_print(ans,arr,dp,prev);
}
void DP_4(){                       // LIS O(nlogn)
    long long n=0,temp=0;
    queue<long long> Q;
    while(cin>>temp){
        Q.push(temp);
        n++;
    }
    vector<long long> arr(n,0); 
    vector<long long> dp(n,0);  //長度i-1的LIS 結尾最小的數字
    vector<long long> LIS(n,0); //以i元素結尾的LIS
    long long ans=0;
    for(long long i=0;i<n;i++){
        arr[i]=Q.front();
        dp[i]=1;
        LIS[i]=1;
        Q.pop();
    }
    dp[ans++]=arr[0];
    for(long long i=1;i<n;i++){
        if(dp[ans-1]<arr[i]){
            dp[ans++]=arr[i];
            LIS[i]=ans;
        }
        else{
            long long l=0,r=ans-1,aa=0;
            while(l<=r){
                long long mid=(l+r)/2;
                if(dp[mid]>=arr[i]){
                    r=mid-1;
                    aa=mid;
                }
                else
                    l=mid+1;
            }
            dp[aa]=arr[i];
            LIS[i]=aa+1;
        }
    }
    cout<<ans<<endl;
    cout<<'-'<<endl;
    stack<long long> ans_arr;
    for(long long i=n-1,t=ans;i>=0 && 0<t;i--){
        if(LIS[i]==t){
            ans_arr.push(arr[i]);
            t--;
        }
    }
    while(!ans_arr.empty()){
        cout<<ans_arr.top()<<endl;
        ans_arr.pop();
    }
}
void DP_5(){
    int n,m;
    for(int T=1;cin>>n>>m;T++){
        if(n==0 && m==0)
            break;
        vector<int> arr1(n);
        vector<int> arr2(m);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        for(int i=0;i<m;i++)
            cin>>arr2[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr1[i-1]==arr2[j-1])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                dp[i][j]=max({dp[i][j],dp[i][j-1],dp[i-1][j]});
            }
        }
        cout<<"Twin Towers #"<<T<<endl;
        cout<<"Number of Tiles : "<<dp[n][m]<<endl;
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // DP_1();
    // DP_2();
    // DP_3();
    // DP_4();
    DP_5();
    return 0;
}