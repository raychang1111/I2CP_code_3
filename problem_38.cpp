// https://www.luogu.com.cn/problem/solution/P1228      //ㅐ�|락 ⅹ쨁 쩵쨁 ⅹ짾 쩵짾
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long pow_self(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
void dfs(pair<int,int> UL,int n,pair<int,int> point){
    if(n==1)
        return ;
    pair<int,int> mid=UL;
    mid.first+=(n/2-1);
    mid.second+=(n/2-1);
    if(point.first<=mid.first){
        if(point.second<=mid.second){
            // 쾧쫇ⅹ쨁
            cout<<mid.first+1<<' '<<mid.second+1<<' '<<1<<endl;
            dfs(UL,n/2,point);
            dfs({UL.first,mid.second+1},n/2,{mid.first,mid.second+1});
            dfs({mid.first+1,UL.second},n/2,{mid.first+1,mid.second});
            dfs({mid.first+1,mid.second+1},n/2,{mid.first+1,mid.second+1});
        }
        else{
            // 쾧쫇쩵쨁
            cout<<mid.first+1<<' '<<mid.second<<' '<<2<<endl;
            dfs(UL,n/2,mid);
            dfs({UL.first,mid.second+1},n/2,point);
            dfs({mid.first+1,UL.second},n/2,{mid.first+1,mid.second});
            dfs({mid.first+1,mid.second+1},n/2,{mid.first+1,mid.second+1});
        }
    }
    else{
        if(point.second<=mid.second){
            // 쾧쫇ⅹ짾
            cout<<mid.first<<' '<<mid.second+1<<' '<<3<<endl;
            dfs(UL,n/2,mid);
            dfs({UL.first,mid.second+1},n/2,{mid.first,mid.second+1});
            dfs({mid.first+1,UL.second},n/2,point);
            dfs({mid.first+1,mid.second+1},n/2,{mid.first+1,mid.second+1});
        }
        else{
            // 쾧쫇쩵짾
            cout<<mid.first<<' '<<mid.second<<' '<<4<<endl;
            dfs(UL,n/2,mid);
            dfs({UL.first,mid.second+1},n/2,{mid.first,mid.second+1});
            dfs({mid.first+1,UL.second},n/2,{mid.first+1,mid.second});
            dfs({mid.first+1,mid.second+1},n/2,point);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int k;
    pair<int,int> point;
    cin>>k>>point.first>>point.second;
    dfs({1,1},pow_self(2,k),point);
    return 0;
}