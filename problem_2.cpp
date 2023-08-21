// https://www.luogu.com.cn/problem/P1102
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,c;
    cin>>n>>c;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    long long prev=0,curr;
    long long ans=0;
    for(int i=arr.size()-1,j=arr.size()-1;i>=0;i--){
        if(i+1<arr.size() && arr[i] == arr[i+1]){
            ans+=prev;
            continue;
        }
        long long b=arr[i]-c;
        curr=0;
        while(0<=j && arr[j]>b)
            j--;
        while(0<=j && arr[j]==b){
            j--;
            curr++;
        }
        ans+=curr;
        prev=curr;
    }
    cout<<ans<<endl;
    return 0;
}
