// https://vjudge.net/problem/UVA-828
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int stoi(string &s){
    int res=0;
    for(int i=0;i<s.size();i++)
        res=res*10+s[i]-'0';
    return res;
}
char ciph_inverse(int n,char c){
    return 'A'+((c-'A'-n)%26+26)%26;
}
bool sol(int i,int n,int m,string &s1,string &s2,string &ans,bool *s1_check){
    if(i>=s2.size()){
        cout<<ans<<endl;
        return true;
    }
    bool res=false; 
    if(s2[i]==' '){
        ans.push_back(' ');
        res|=sol(i+1,n,m,s1,s2,ans,s1_check);
        ans.pop_back();
    }
    else if(i+2<s2.size() && s2[i]==s1[m] && s2[i+2]==s1[(m+1)%s1.size()]){         //先塞條件較嚴苛的
        ans.push_back(ciph_inverse(n,s2[i+1]));
        res|=sol(i+3,n,(m+1)%s1.size(),s1,s2,ans,s1_check);
        ans.pop_back();
    }
    else if(!s1_check[ciph_inverse(n,s2[i])-'A']){                                  //再用寬鬆條件的
        ans.push_back(ciph_inverse(n,s2[i]));
        res|=sol(i+1,n,m,s1,s2,ans,s1_check);
        ans.pop_back();
    }
    return res;
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    string temp;
    getline(cin,temp);
    int t=stoi(temp);
    while(t--){
        int n,q;
        bool s1_check[26]={};
        string s1;
        getline(cin,temp);
        getline(cin,s1);
        getline(cin,temp);
        n=stoi(temp);
        getline(cin,temp);
        q=stoi(temp);
        for(int i=0;i<s1.size();i++)
            s1_check[s1[i]-'A']=true;
        
        while(q--){
            int m=0;
            string s2,ans;
            getline(cin,s2);
            
            if(!sol(0,n,0,s1,s2,ans,s1_check))
                cout<<"error in encryption"<<endl;
        }
        if(t!=0)
            cout<<endl;
    }
    return 0;
}

// ABCDEFGHIJKLMNOPQRSTUVWXYZ