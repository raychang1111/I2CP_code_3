// https://www.luogu.com.cn/problem/P2058
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,t,k;
    cin>>n;
    int count=0;
    vector<int> nation(100005,0);
    queue<pair<int,int>> Q; //time : index
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++){
        cin>>t>>k;
        arr[i]=vector<int>(k);
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
            if(nation[arr[i][j]]==0)
                count++;
            nation[arr[i][j]]++;
        }
        while(!Q.empty() && t-86400>=Q.front().first){
            for(int j=0;j<arr[Q.front().second].size();j++){
                nation[arr[Q.front().second][j]]--;
                if(nation[arr[Q.front().second][j]]==0)
                    count--;
            }
            Q.pop();
        }
        Q.push({t,i});
        cout<<count<<'\n';
    }
    return 0;
}