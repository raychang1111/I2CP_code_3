#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,long long &x,long long &y){   //�ݮi�ڴX���o
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
long long inv(long long a,long long p){ //�Da�bmod p �U���f��   �Ωݮi�ڴX���o�D�f��(�n�B p���@�w�n����� ��a p�@�w�n����)
    long long x,y;
    int temp=exgcd(a,p,x,y);
    if(temp==1)    //a p ����Ұf���~�s�b (���� ax=1(mod p) => ax+py=1=gcd(a,p))
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
long long inv_2(long long a,long long p){  //�Da�bmod p �U���f��   �ζO���p�w�z�D�f��(p�@�w�n����� �Ba p�@�w�n����)
    
    return pow(a,p-2,p);
}
int main(){
    // ��@�զX�k�� ax+by=gcd(a,b)
    // ���� aX+bY=gcd(a,b)=gcd(b,a%b)=bx+(a%b)y
    // aX+bY=bx+(a-(a/b���U����)*b)y
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
        cout<<"�f�����s�b\n";
    else
        cout<<a<<"�bmod "<<p<<"�U���f����"<<invv<<'\n';
    cout<<"�ζO���p�w�z�D\n";   //p�n�O>1����� �B ap���� �_�h�O���~��X
    cout<<a<<"�bmod "<<p<<"�U���f����"<<inv_2(a,p)<<'\n';
    // ----------------------------------------------------------
    return 0;
}