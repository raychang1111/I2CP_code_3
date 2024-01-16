// https://vjudge.net/problem/UVA-10443
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char R='R',S='S',P='P';
void dfs(int i,int j,vector<vector<char>> &arr,vector<vector<char>> &temp,vector<vector<bool>> &run){
    run[i][j]=true;
    if(temp[i][j]==R){
        if(i+1<arr.size()){
            if(temp[i+1][j]==S)
                arr[i+1][j]=R;
            else if(temp[i+1][j]==P)
                arr[i][j]=P;
        }
        if(j+1<arr[0].size()){
            if(temp[i][j+1]==S)
                arr[i][j+1]=R;
            else if(temp[i][j+1]==P)
                arr[i][j]=P;
        }
    }
    else if(temp[i][j]==S){
        if(i+1<arr.size()){
            if(temp[i+1][j]==P)
                arr[i+1][j]=S;
            else if(temp[i+1][j]==R)
                arr[i][j]=R;
        }
        if(j+1<arr[0].size()){
            if(temp[i][j+1]==P)
                arr[i][j+1]=S;
            else if(temp[i][j+1]==R)
                arr[i][j]=R;
        }
    }
    else if(temp[i][j]==P){
        if(i+1<arr.size()){
            if(temp[i+1][j]==R)
                arr[i+1][j]=P;
            else if(temp[i+1][j]==S)
                arr[i][j]=S;
        }
        if(j+1<arr[0].size()){
            if(temp[i][j+1]==R)
                arr[i][j+1]=P;
            else if(temp[i][j+1]==S)
                arr[i][j]=S;
        }
    }
    if(i+1<arr.size() && !run[i+1][j])
        dfs(i+1,j,arr,temp,run);
    if(j+1<arr[0].size() && !run[i][j+1])
        dfs(i,j+1,arr,temp,run);
}
void d_1(vector<vector<char>> &arr){
    vector<vector<bool>> run(arr.size(),vector<bool>(arr[0].size()));
    vector<vector<char>> temp=arr;
    dfs(0,0,arr,temp,run);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n,m,d;
    cin>>t;
    while(t--){
        cin>>n>>m>>d;
        vector<vector<char>> arr(n,vector<char>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>arr[i][j];
        while(d--)
            d_1(arr);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<arr[i][j];
            cout<<endl;
        }
        if(t!=0)
            cout<<endl;
    }
    return 0;
}