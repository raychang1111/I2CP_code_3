// https://www.luogu.com.cn/problem/P4387
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        vector<int> pushed(n);
        vector<int> poped(n);
        stack<int> st;
        for(int i=0;i<n;i++)
            cin>>pushed[i];
        for(int i=0;i<n;i++)
            cin>>poped[i];
        int i=0,j=0;
        while(i<n || j<n){
            if(st.empty()){
                st.push(pushed[i]);
                i++;
            }
            else if(i<n && st.top()!=poped[j]){
                st.push(pushed[i]);
                i++;
            }
            else if(j<n && st.top()==poped[j]){
                st.pop();
                j++;
            }
            else
                break;
        }
        if(i==n && j==n)
            cout<<"Yes\n";
        else 
            cout<<"No\n";
    }
    return 0;
}