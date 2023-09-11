// https://www.luogu.com.cn/problem/P1928
#include <bits/stdc++.h>
using namespace std;
int str_to_nb(string s){
    int res=0;
    for(char c:s)
        res=res*10+c-'0';
    return res;
}
string decoding(int l,int r,string &s){
    int repeat;
    bool double_number=('0'<=s[l+2] && s[l+2]<='9');
    if(double_number){
        repeat=str_to_nb(s.substr(l+1,2));
        l+=3;
        r-=1;
    }
    else{
        repeat=str_to_nb(s.substr(l+1,1));
        l+=2;
        r-=1;
    }
    stack<int> st;
    string res,ans;
    for(int i=l;i<=r;i++){
        if(s[i]=='[')
            st.push(i);
        else if(s[i]==']'){
            int temp=st.top();
            st.pop();
            if(st.empty())
                res+=decoding(temp,i,s);
        }
        else{
            if(st.empty())
                res+=s[i];
        }
    }
    while(repeat){
        if(repeat & 1)
            ans+=res;
        res=res+res;
        repeat>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    s=("[1"+s+"]");
    cout<<decoding(0,s.size()-1,s)<<endl;
    return 0;
}