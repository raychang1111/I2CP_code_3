// https://www.luogu.com.cn/problem/P4147  懸線法(求最大子矩形長方型)
#include <bits/stdc++.h>
using namespace std;
int arr[1007];
int l[1007];
int r[1007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c;
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c=='F')
                arr[j]++;
            else    
                arr[j]=0;
            l[j]=r[j]=j; 
        }
        for(int j=0;j<m;j++){
            while(0<l[j] && arr[j]<=arr[l[j]-1]){
                l[j]=l[j]-1;
            }
        }
        for(int j=m-1;j>=0;j--){
            while(r[j]+1<m && arr[j]<=arr[r[j]+1]){
                r[j]=r[j]+1;
            }
        }
        for(int j=0;j<m;j++)
            ans=max(ans,3*arr[j]*(r[j]-l[j]+1));
    }
    cout<<ans<<'\n';
    return 0;
}