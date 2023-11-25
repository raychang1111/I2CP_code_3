// https://vjudge.net/problem/UVA-442
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    long long ans;
    char c;
    string s;
    cin>>n;
    vector<pair<int,int>> matrix(n);
    for(int i=0;i<n;i++)
        cin>>c>>matrix[i].first>>matrix[i].second;
    while(cin>>s){
        ans=0;
        bool flag=false;
        stack<pair<int,int>> st;
        st.push({0,0});
        for(int i=0;!flag && i<s.size();i++){
            if(s[i]=='(')
                st.push({0,0});
            else if(s[i]==')'){
                pair<int,int> temp=st.top();
                st.pop();
                if(st.top().second==0)
                    st.top()=temp;
                else{
                    if(st.top().second==temp.first){
                        ans+=(st.top().first*st.top().second*temp.second);
                        st.top().second=temp.second;
                    }
                    else
                        flag=true;
                }
            }
            else{
                if(st.top().second==0)
                    st.top()=matrix[s[i]-'A'];
                else{
                    if(st.top().second==matrix[s[i]-'A'].first){
                        ans+=(st.top().first*st.top().second*matrix[s[i]-'A'].second);
                        st.top().second=matrix[s[i]-'A'].second;
                    }
                    else    
                        flag=true;
                }
            }
        }
        if(flag)
            cout<<"error"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}