// https://www.luogu.com.cn/problem/P1217
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<long long> ans;
int pow_self(int x,int y){
    int res=1;
    while(y){
        if(y&1)
            res*=x;
        y>>=1;
        x*=x;
    }
    return res;
}
int digits(int x){
    int res=0;
    while(x>0){
        res++;
        x/=10;
    }
    return res;
}
void check(int path){
    if(path<2)
        return ;
    for(int i=2;i<=sqrt(path);i++)
        if(path%i==0)
            return ;
    ans.push_back(path);
    // cout<<path<<endl;
}
void dfs(int i,int deep,int &path,const int &a,const int &b){
    if(deep==i){
        if(a<=path && path<=b)
            check(path);
        return ;
    }
    if(deep==0 && i%2!=0){
        for(int j=0;j<10;j++){
            path=j;
            dfs(i,deep+1,path,a,b);
            path=0;
        }
    }
    else{
        int start=0,step=1;
        if(deep+2==i)
            step=2,start=1;
        for(int j=start;j<10;j+=step){
            path+=j*pow_self(10,deep);
            path*=10;
            path+=j;
            dfs(i,deep+2,path,a,b);
            path/=10;
            path-=j*pow_self(10,deep);
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b,path=0;
    cin>>a>>b;
    int n=digits(a),m=digits(b);
    for(int i=n;i<=m;i++)
        dfs(i,0,path,a,b);
    sort(ans.begin(),ans.end());
    for(int aa:ans)
        cout<<aa<<endl;
    return 0;
}