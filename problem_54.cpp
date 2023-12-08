// https://vjudge.net/problem/UVA-10093
#include <bits/stdc++.h>                //關鍵 mod 
using namespace std;
int value(char c){
    int res;
    if('0'<=c && c<='9')
        res=c-'0';
    else if('A'<=c && c<='Z')
        res=c-'A'+10;
    else if('a'<=c && c<='z')
        res=c-'a'+36;
    else                    //要考慮'-'的情況 但負數不影響所以省略
        res=0;
    return res;
}
int main(){
    int ans;
    string s;
    while(cin>>s){
        ans=0;
        bool flag=true;
        int start=1;
        for(int j=0;j<s.size();j++){
            start=max(start,value(s[j]));
            ans+=value(s[j]);
        }
        for(int i=start+1;flag && i<=62;i++){
            if(ans%(i-1)==0){
                flag=false;
                cout<<i<<endl;
            }
        }
        if(flag)
            cout<<"such number is impossible!"<<endl;
    }
}