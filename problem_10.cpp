// https://www.luogu.com.cn/problem/P1163
#include <iostream>
#include <iomanip>
#define EPS 0.0001
using namespace std;
double f(double r,double a,int b,int c){
    for(int i=0;i<c;i++){
        a+=a*r;
        a-=b;
    }
    return a; 
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    double l=0,r=100,ans=0;
    while(l<=r){
        double mid=(l+r)/2;
        if(f(mid,a,b,c)<0){
            l=mid+EPS;
            ans=mid;
        }
        else
            r=mid-EPS;
    }
    cout<<fixed<<setprecision(1)<<ans*100<<endl;
    return 0;
}