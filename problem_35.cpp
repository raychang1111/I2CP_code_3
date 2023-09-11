// https://www.luogu.com.cn/problem/P3612
#include<bits/stdc++.h>
using namespace std;
long long pow_f(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
long long log_2(long long x){
    long long res=0;
    while(x){
        x/=2;
        res++;
    }
    return res-1;
}
char s_index(long long n,string &s){
    if(n<=s.size())
        return s[n-1];
    long long i=log_2(n/s.size());
    long long j=s.size()*pow_f(2,i);
    if(n-j==1)
        return s_index(j,s);
    else if(n==j)
        return s_index(j/2-1,s);
    else 
        return s_index(n-j-1,s);
}
int main(){
    string s;
    long long n;
    cin>>s>>n;
    cout<<s_index(n,s)<<endl;
    return 0;
}