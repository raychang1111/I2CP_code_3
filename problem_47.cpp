// https://vjudge.net/problem/UVA-10161
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool is_odd(int a){     //是不是基數
    return a&1;
}
pair<int,int> run(int i){
    int n=sqrt(i);
    pair<int,int> res;
    if(is_odd(n)){  
        res={1,n};
        for(int j=1;j<=i-n*n;j++){
            if(j==1){
                res.second++;
            }
            else if(j<=1+n){
                res.first++;
            }
            else{
                res.second--;
            }
        }
    }
    else{
        res={n,1};
        for(int j=1;j<=i-n*n;j++){
            if(j==1){
                res.first++;
            }
            else if(j<=1+n){
                res.second++;
            }
            else{
                res.first--;
            }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n && n!=0){
        pair<int,int> ans=run(n);
        cout<<ans.first<<' '<<ans.second<<endl;
    }
    return 0;
}