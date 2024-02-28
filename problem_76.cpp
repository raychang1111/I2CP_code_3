// https://www.luogu.com.cn/problem/P1019       
// °ò¤KÃD
#include <bits/stdc++.h>
#define int long long
#define s first
#define t second
using namespace std;
int check(string &s1,string &s2){
    int res=0;
    for(int i=1;i<min(s1.size(),s2.size()) && res==0;i++){
        bool flag=true;
        for(int j=1;flag && j<=i;j++)
            flag=(s1[s1.size()-i-1+j]==s2[j-1]);
        if(flag)
            res=i;
    }
    return res;
}   
int dfs(string &ans,vector<pair<string,int>> &data){
    int res=ans.size();
    for(int j=0;j<data.size();j++){
        if(data[j].t>0){
            int temp=check(ans,data[j].s);
            if(temp>0){
                for(int k=temp;k<data[j].s.size();k++)
                    ans.push_back(data[j].s[k]);
                data[j].t--;
                res=max(res,dfs(ans,data));
                for(int k=temp;k<data[j].s.size();k++)
                    ans.pop_back();
                data[j].t++;
            }
        }
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,res=0;
    cin>>n;
    string ans;
    vector<pair<string,int>> data(n);
    for(int i=0;i<n;i++){
        cin>>data[i].s;
        data[i].t=2;
    }
    cin>>ans;
    for(int i=0;i<n;i++){
        if(data[i].s[0]==ans[0]){
            ans=data[i].s;
            data[i].t--;
            res=max(res,dfs(ans,data));
            data[i].t++;
            ans=data[i].s[0];
        }
    }
    cout<<res<<'\n';
    // string s1="aaa",s2="aa";
    // cout<<check(s1,s2);
    return 0;
}