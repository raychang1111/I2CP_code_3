#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,long long &x,long long &y){   //拓展歐幾里得
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int res=exgcd(b,a%b,x,y);
    int new_x=y;
    int new_y=x-a/b*y;
    x=new_x;
    y=new_y;
    return res;
}
long long inv(long long a,long long p){ //求a在mod p 下的逆元   用拓展歐幾里得求逆元(好處 p不一定要為質數 但a p一定要互質)
    long long x,y;
    int temp=exgcd(a,p,x,y);
    if(temp==1)    //a p 互質模逆元才存在 (推導 ax=1(mod p) => ax+py=1=gcd(a,p))
        return (x+p)%p;
    else
        return -1;
}
long long pow(long long x,long long y,long long p){
    long long res=1;
    while(y){
        if(y&1){
            res=(res*x)%p;
        }
        x=(x*x)%p;
        y>>=1;
    }
    return res;
}
long long inv_2(long long a,long long p){  //求a在mod p 下的逆元   用費馬小定理求逆元(p一定要為質數 且a p一定要互質)
    
    return pow(a,p-2,p);
}
int main(){
    // 找一組合法的 ax+by=gcd(a,b)
    // 推導 aX+bY=gcd(a,b)=gcd(b,a%b)=bx+(a%b)y
    // aX+bY=bx+(a-(a/b取下高斯)*b)y
    // aX+bY=bx+ay-a/b*b*y
    // aX+bY=ay+b(x-a/b*y) 
    // X=y Y=x-a/b*y
    int a,b,p;
    // ----------------------------------------------------------
    // cin>>a>>b;
    // long long x,y;
    // cout<<exgcd(a,b,x,y)<<'\n';
    // cout<<a<<"x+"<<b<<"y=gcd("<<a<<','<<b<<")"<<'\n';
    // cout<<"x="<<x<<'\n';
    // cout<<"y="<<y<<'\n';
    // ----------------------------------------------------------
    cin>>a>>p;
    int invv=inv(a,p);
    if(invv<0)
        cout<<"逆元不存在\n";
    else
        cout<<a<<"在mod "<<p<<"下的逆元為"<<invv<<'\n';
    cout<<"用費馬小定理求\n";   //p要是>1的質數 且 ap互質 否則是錯誤輸出
    cout<<a<<"在mod "<<p<<"下的逆元為"<<inv_2(a,p)<<'\n';
    // ----------------------------------------------------------
    return 0;
}