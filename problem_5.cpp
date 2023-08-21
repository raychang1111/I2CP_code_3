// https://www.luogu.com.cn/problem/P1678
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> arr(n);
    vector<long long> t(m);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        cin>>t[i];
    sort(arr.begin(),arr.end());
    long long ans=0;
    for(int i=0;i<m;i++){
        int l=0,r=arr.size()-1;
        long long dis=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==t[i]){
                dis=0;
                break;
            }
            else if(arr[mid]<t[i]){
                l=mid+1;
                dis=min(dis,abs(arr[mid]-t[i]));
            }
            else{
                r=mid-1;
                dis=min(dis,abs(arr[mid]-t[i]));
            }
        }
        ans+=dis;
    }
    cout<<ans<<endl;
    return 0;
}