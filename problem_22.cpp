// https://www.luogu.com.cn/problem/P1149
#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
set<vector<int>> ans;
int count(int l,int r,vector<int> &arr){
    int res=0;
    if(0<=l && r<=arr.size()){
        for(int i=l;i<=r;i++)
            res=res*10+arr[i];
    }
    return res;
}
void dfs(int n,vector<int> &path,vector<int> &number){
    if(n==0){
        vector<int> arr=path;
        sort(arr.begin(),arr.end());
        do{
            for(int i=0;i<arr.size()-2;i++){
                for(int j=i+1;j<arr.size()-1;j++){
                    int a=count(0,i,arr);
                    int b=count(i+1,j,arr);
                    int c=count(j+1,arr.size()-1,arr);
                    if(a+b==c){
                        ans.insert({a,b,c});
                    }
                }
            }
        }while(next_permutation(arr.begin(),arr.end()));
        return ;
    }
    for(int i=0;i<number.size();i++){
        if(n-number[i]<0)
            continue;
        path.push_back(i);
        dfs(n-number[i],path,number);
        path.pop_back();
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    vector<int> number={6,2,5,5,4,5,6,3,7,6};
    vector<int> path;
    cin>>n;
    if(n<=4)
        cout<<0<<endl;
    else{
        dfs(n-4,path,number);
        cout<<ans.size()<<endl;
    }
    return 0;
}