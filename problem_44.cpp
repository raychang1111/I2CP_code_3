// https://zerojudge.tw/ShowProblem?problemid=e602      位元 前墜和
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    long long a,b;
    for(long long T=1;cin>>a>>b;T++){
        if(a==0 && b==0)
            break;
        b++;
        long long count_a=0,count_b=0;
        for(int i=0;i<31;i++){
            count_a+=(a/(1<<(i+1))*(1<<i)+max((long long)0,a%(1<<(i+1))-(1<<i)));
            count_b+=(b/(1<<(i+1))*(1<<i)+max((long long)0,b%(1<<(i+1))-(1<<i)));
        }
        cout<<"Case "<<T<<": "<<count_b-count_a<<endl;
    }
    return 0;
}
