// https://www.luogu.com.cn/problem/P1618
#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;
bool flag=false;
long long pow_self(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}
bool same(double a,double b,double c){
    return abs(a-b)<EPS && abs(a-c)<EPS;
}
void check(long long i,int &a,int &b,int &c){
    int temp1=i/1000000;
    int temp2=i/1000-temp1*1000;
    int temp3=i-temp2*1000-temp1*1000000;
    if(same((double)temp1/(double)a,(double)temp2/(double)b,(double)temp3/(double)c)){
        flag=true;
        cout<<temp1<<' '<<temp2<<' '<<temp3<<endl;
    }
}
void Backtracking(int deep,int &run,long long &path,int &a,int &b,int &c){
    if(deep >= 9){
        check(path,a,b,c);
        return ;
    }
    for(int i=0;i<9;i++){
        if(!(run>>i & 1)){
            run |= (1<<i);
            path+=(i+1)*pow_self(10,8-deep);
            Backtracking(deep+1,run,path,a,b,c);
            path-=(i+1)*pow_self(10,8-deep);
            run &= ~(1<<i);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b,c,run=0;
    long long path=0;
    cin>>a>>b>>c;
    Backtracking(0,run,path,a,b,c);
    if(!flag)
        cout<<"No!!!"<<endl;
    return 0;
}