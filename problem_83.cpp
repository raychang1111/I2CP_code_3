//  https://www.luogu.com.cn/problem/P3613  ¸ê®Æµ²ºc
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,q,a,b,c,d;
    cin>>n>>q;
    map<pair<int,int>,int> hash;
    for(int i=0;i<q;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            hash[{b,c}]=d;
        }
        else{
            cin>>b>>c;
            cout<<hash[{b,c}]<<'\n';
        }
    }
    return 0;
}
