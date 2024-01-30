// https://www.luogu.com.cn/problem/P1135
#include <bits/stdc++.h>
using namespace std;
int bfs(int s,int e,vector<int> &arr){
    vector<int> dp(arr.size(),-1);
    int val=0,n;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        n=Q.size();
        #pragma omp parallel    //是OMP中的一個指令，表示接下來的for循環將被多線程執行，另外每次循環之間不能有關係
        for(int i=0;i<n;i++){
            if(dp[Q.front()]==-1 || dp[Q.front()]>val){
                dp[Q.front()]=val;
                if(Q.front()+arr[Q.front()]<arr.size())
                    Q.push(Q.front()+arr[Q.front()]);
                if(0<=Q.front()-arr[Q.front()])
                    Q.push(Q.front()-arr[Q.front()]);
            }
            Q.pop();
        }
        val++;
    }
    return dp[e];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<bfs(a-1,b-1,arr)<<'\n';
    return 0;
}