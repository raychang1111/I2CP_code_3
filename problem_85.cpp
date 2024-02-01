// https://www.luogu.com.cn/problem/P1996 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        arr[i]=i+1;
    int ptr=k-1;
    while(!arr.empty()){
        ptr%=arr.size();
        cout<<arr[ptr]<<' ';
        arr.erase(arr.begin()+ptr);
        ptr+=(k-1);
    }
    return 0;
}
//0 1 2 3 4 5 6 7 8 9
//1 2 3 4 5 6 7 8 9 10
//1 2 4 5 6 7 8 9 10