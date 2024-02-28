// https://www.luogu.com.cn/problem/P3817   貪心
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,ans=0,temp;
    cin>>n>>x;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i+1<arr.size();i++){
        //如果我們吃掉第一個裡的，只會減少一個分組的量，
        //而如果吃掉第二個裡的，可以減少2個分組的量。 
        //所以我們要盡量吃掉第二個裡的糖果
        temp=arr[i]+arr[i+1]-x;
        if(temp<=0)
            continue;
        ans+=temp;
        if(arr[i+1]<temp){
            temp-=arr[i+1];
            arr[i+1]=0;
            arr[i]-=temp;
        }
        else
            arr[i+1]-=temp;
    }
    cout<<ans<<endl;
    return 0;
}