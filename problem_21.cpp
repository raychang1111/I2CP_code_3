// https://www.luogu.com.cn/problem/P1217
#include <bits/stdc++.h>
using namespace std;
int digits(int x){
    int res=0;
    while(x>0){
        res++;
        x/=10;
    }
    return res;
}
int dfs(int i,int deep,int &path,const int &a,const int &b){
    if(deep==i){
        if(check(path))
            return 1;
        return 0;
    }
    if(i%2!=0){
        for(int j=0;j<10;j++)
            path=j+10^(i/2);
    }
    else{

    }
}
int main(){
    int a,b,path=0;
    cin>>a>>b;
    int n=digits(a),m=digits(b);
    for(int i=n;i<=m;i++)
        dfs(i,path,a,b);
    return 0;
}