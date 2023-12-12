// https://www.luogu.com.cn/problem/P3601
#include <bits/stdc++.h>            //歐拉函數 Fi(n)            //數論題 待解
using namespace std;
const long long mod=666623333;
bool prime[4000000];    
void prime_init(vector<long long> &prime_list){
    for(long long i=2;i<=1000000;i++)
        prime[i]=true;
    for(long long i=2;i<=1000000;i++){
        if(!prime[i])
            continue;
        prime_list.push_back(i);
        for(long long j=i;j*i<=1000000;j++) 
            prime[j*i]=false;
    }
}

int main(){
    long long l,r,ans=0;
    cin>>l>>r;
    vector<long long> prime_list;
    prime_init(prime_list);
    // for(int i=0;prime_list[i]<100;i++)
    //     cout<<prime_list[i]<<' ';
    for(long long i=l;i<=r;i++){
        
    }
    cout<<ans<<endl;
    return 0;
}