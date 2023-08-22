// https://www.luogu.com.cn/record/122308542
#include <bits/stdc++.h>
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
        for(int i=0;i<path.size()-2;i++){
            for(int j=i+1;j<path.size()-1;j++){
                if(path[0]==0 && i!=0 || path[i+1]==0 && j!=i+1 || path[j+1]==0 && j+1!=path.size()-1)
                    continue;
                int a=count(0,i,path);
                int b=count(i+1,j,path);
                int c=count(j+1,path.size()-1,path);
                if(a+b==c){
                    ans.insert({a,b,c});
                }
            }
        }
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
int main(){
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