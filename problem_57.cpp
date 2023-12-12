// https://www.luogu.com.cn/problem/P2660
#include <bits/stdc++.h>
using namespace std;
long long cost(long long x,long long y){
    if(x==0)
        return 0;
    return (y/x)*x*4+cost(y%x,x);
}
int main(){ 
    long long x,y;
    cin>>x>>y;
    cout<<cost(min(x,y),max(x,y))<<endl;
    return 0;
}