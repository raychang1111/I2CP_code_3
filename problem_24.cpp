// https://www.luogu.com.cn/problem/P2392
#include <bits/stdc++.h>
using namespace std;
int dfs(int deep,vector<int> &arr,int left,int right){
    if(deep==arr.size())
        return max(left,right);
    return min(dfs(deep+1,arr,left+arr[deep],right),dfs(deep+1,arr,left,right+arr[deep]));
}
int main(){
    int n[4]={},ans=0,temp;
    for(int i=0;i<4;i++)
        cin>>n[i];
    vector<vector<int>> arr(4);
    for(int i=0;i<4;i++)
        for(int j=0;j<n[i];j++){
            cin>>temp;
            arr[i].push_back(temp);
        }
    for(int i=0;i<4;i++)
        ans+=dfs(0,arr[i],0,0);
    cout<<ans<<endl;
    return 0;
}