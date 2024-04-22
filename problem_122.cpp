// https://www.luogu.com.cn/problem/P1010
#include <bits/stdc++.h>
using namespace std;
void D_C(int n){
    if(n==0){
        cout<<"0";
    }
    else{
        stack<int> st;
        for(int i=0;n;i++){
            if(n&1)
                st.push(i);
            n>>=1;
        }
        bool flag=false;
        while(!st.empty()){
            if(flag)
                cout<<"+";
            if(st.top()==1)
                cout<<"2";
            else{
                cout<<"2(";
                D_C(st.top());
                cout<<")";
            }     
            st.pop();
            flag=true;
        }
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    D_C(n);
    cout<<'\n';
    return 0;
}