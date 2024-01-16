// https://vjudge.net/problem/UVA-11121
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void print_self(long long ans){
    if(ans!=0){
        print_self(ans>>1);
        cout<<(ans&1);
    }
}
void print_2(long long x){
    long long res=0;
    long long b=1;
    for(int i=0;(x>>i)>0;i++){
        if(x>>i&1)
            res+=b;
        b*=-2;
    }
    cout<<res<<endl;
}
long long add__n2(long long x,long long y){         //base: -2 ªº¥[ªk
    long long carry=0,curr,temp;
    long long res=0;
    for(long long i=0;(carry>>i)>0 || (x>>i)>0 || (y>>i)>0;i++){
        curr=(carry>>i&1)+(x>>i&1)+(y>>i&1);
        temp=0;
        if(curr/2 >temp && (x>>(i+1)&1)){
            x&=~((long long)1<<(i+1));
            temp++;
        }
        if(curr/2 >temp && (y>>(i+1)&1)){
            y&=~((long long)1<<(i+1));
            temp++;
        }    
        if((curr/2-temp)!=0){
            carry|=((long long)1<<(i+1));
            carry|=((long long)1<<(i+2));
        }
        // cout<<"-------------------"<<endl;
        // print_self(x);
        // cout<<endl;
        // print_self(y);
        // cout<<endl;
        // cout<<carry<<endl;
        // cout<<"-------------------"<<endl;
        if(curr%2)
            res|=((long long)1<<i);
    }
    return res;
}
long long sol_positive(long long x,bool is_odd){
    long long a=0,b=0;
    for(int i=0;(x>>i)>0;i+=2){
        if((x>>i)&1){
            a|=((long long)1<<i);
            if(!is_odd)
                a|=((long long)1<<(i+1));
        }
    // cout<<i<<' ';
    // print_self(a);
    // cout<<endl;
    }
    for(int i=1;(x>>i)>0;i+=2){
        if((x>>i)&1){
            b|=((long long)1<<i);
            if(is_odd)
                b|=((long long)1<<(i+1));
        }
    }
    // print_self(a);
    // cout<<endl;
    // print_self(b);
    // cout<<endl;
    // print_self(add__n2(a,b));
    // cout<<endl;
    return add__n2(a,b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,x;
    cin>>n;
    for(long long cc=1;cc<=n;cc++){
        cin>>x;
        // print_self(x);
        // cout<<endl;
        long long ans;
        if(x<0)
            ans=sol_positive(abs(x),false);
        else
            ans=sol_positive(x,true);
        // print_2(ans);
        cout<<"Case #"<<cc<<": ";
        if(!ans)
            cout<<0;
        else
            print_self(ans);
        cout<<endl;
    }
    return 0;
}