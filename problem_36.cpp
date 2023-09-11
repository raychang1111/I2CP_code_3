// https://www.luogu.com.cn/problem/P1259
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void dfs(int deep,int n){
    if(n==4){
        cout<<"oooo****--";
        for(int i=0;i<deep;i++)
            cout<<"o*";
        cout<<endl;
        cout<<"ooo--***o*";
        for(int i=0;i<deep;i++)
            cout<<"o*";
        cout<<endl;
        cout<<"ooo*o**--*";
        for(int i=0;i<deep;i++)
            cout<<"o*";
        cout<<endl;
        cout<<"o--*o**oo*";
        for(int i=0;i<deep;i++)
            cout<<"o*";
        cout<<endl;
        cout<<"o*o*o*--o*";
        for(int i=0;i<deep;i++)
            cout<<"o*";
        cout<<endl;
        cout<<"--o*o*o*o*";
        for(int i=0;i<deep;i++)
            cout<<"o*";
        cout<<endl;
        return ;
    }
    for(int i=0;i<n;i++)
        cout<<'o';
    for(int i=0;i<n;i++)
        cout<<'*';
    cout<<"--";
    for(int i=0;i<deep;i++)
        cout<<"o*";
    cout<<endl;

    for(int i=0;i<n-1;i++)
        cout<<'o';
    cout<<"--";
    for(int i=0;i<n-1;i++)
        cout<<'*';
    for(int i=0;i<deep+1;i++)
        cout<<"o*";
    cout<<endl;
    dfs(deep+1,n-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    dfs(0,n);
    return 0;
}