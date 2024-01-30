// https://www.luogu.com.cn/problem/P1219
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void backtracking(int i,int n,vector<int> &checkerboard,vector<int> &check,int &ans){
    if(i>=n){
        if(ans<3){
            for(int i=0;i<checkerboard.size();i++)
                cout<<checkerboard[i]<<' ';
            cout<<endl;
        }
        ans++;
        return ;
    }
    for(int j=1;j<=n;j++){
        if(!(check[0]>>((i+1+j)%(2*n-1))&1) && !(check[1]>>((i+1-j)%(2*n-1))&1) && !(check[2]>>(j%n)&1)){
            check[0]|=1<<((i+1+j)%(2*n-1));
            check[1]|=1<<((i+1-j)%(2*n-1));
            check[2]|=1<<(j%n);
            checkerboard[i]=j;
            backtracking(i+1,n,checkerboard,check,ans);
            checkerboard[i]=0;
            check[0]&=~(1<<((i+1+j)%(2*n-1)));
            check[1]&=~(1<<((i+1-j)%(2*n-1)));
            check[2]&=~(1<<(j%n));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> checkerboard(n,0);
    vector<int> check(3,0);
    backtracking(0,n,checkerboard,check,ans);
    cout<<ans<<endl;
    return 0;
}
