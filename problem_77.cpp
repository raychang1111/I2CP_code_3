// https://www.luogu.com.cn/problem/P1101
#include <bits/stdc++.h>
using namespace std;
string target="yizhong";
void check(int i,int j,vector<vector<char>> &arr,vector<vector<char>> &ans){
    bool d1=true,d2=true,d3=true,d4=true,d5=true,d6=true,d7=true,d8=true;
    for(int k=0;k<target.size();k++){
        d1&=(j+k<arr[0].size() && target[k]==arr[i][j+k]);
        d2&=(i+k<arr.size() && j+k<arr[0].size() && target[k]==arr[i+k][j+k]);
        d3&=(i+k<arr.size() && target[k]==arr[i+k][j]);
        d4&=(i+k<arr.size() && 0<=j-k && target[k]==arr[i+k][j-k]);
        d5&=(0<=j-k && target[k]==arr[i][j-k]);
        d6&=(0<=i-k && 0<=j-k && target[k]==arr[i-k][j-k]);
        d7&=(0<=i-k && target[k]==arr[i-k][j]);
        d8&=(0<=i-k && j+k<arr[0].size() && target[k]==arr[i-k][j+k]);
    }
    for(int k=0;k<target.size();k++){
        if(d1)
            ans[i][j+k]=target[k];
        if(d2)
            ans[i+k][j+k]=target[k];
        if(d3)
            ans[i+k][j]=target[k];
        if(d4)
            ans[i+k][j-k]=target[k];
        if(d5)
            ans[i][j-k]=target[k];
        if(d6)
            ans[i-k][j-k]=target[k];
        if(d7)
            ans[i-k][j]=target[k];
        if(d8)
            ans[i-k][j+k]=target[k];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char>(n));
    vector<vector<char>> ans(n,vector<char>(n,'*'));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==target[0])
                check(i,j,arr,ans);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    return 0;
}