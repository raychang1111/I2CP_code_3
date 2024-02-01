// https://www.luogu.com.cn/problem/P3156   超級簡單入門題
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<q;i++){
        cin>>n;
        cout<<arr[n-1]<<'\n';
    }
    return 0;
}