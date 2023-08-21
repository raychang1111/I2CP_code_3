// https://www.luogu.com.cn/problem/P1036
#include <bits/stdc++.h>
using namespace std;
void init_prime(vector<bool> &prime){
    for(int i=0;i<2;i++)
        prime[i]=false;
    for(int i=2;i<prime.size();i++){
        if(prime[i]){
            for(int j=i;i*j<prime.size();j++)
                prime[i*j]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,N=0,ans=0;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        N+=arr[i];
    }
    vector<bool> prime(N+1,true);
    init_prime(prime);
    for(int i=1;i<(1<<n);i++){
        int temp=k,x=0;
        for(int j=0;j<n;j++){
            if(i>>j&1){
                temp--;
                x+=arr[j];
            }
        }
        if(temp==0 && prime[x])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}