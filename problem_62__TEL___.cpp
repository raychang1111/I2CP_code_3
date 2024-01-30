// https://vjudge.net/problem/UVA-12546             //TLE
/*
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long mod =1000000007;
void backtracking1(int i,long long val,vector<long long> &arr,vector<pair<long long,long long>> &prime){
    if(i==prime.size()){
        arr.push_back(val);
        return ;
    }
    for(long long j=0,temp_val=1;j<=prime[i].second;j++){
        backtracking1(i+1,(val*temp_val)%mod,arr,prime);
        temp_val=(temp_val*prime[i].first)%mod;
    }
}
long long backtracking2(int i,int deep,int prev,vector<long long> &arr){
    long long res=0;
    if(deep==2){
        if(arr[i]*arr[prev]==arr.back()*__gcd(arr[i],arr[prev])){
            res+=(arr[i]+arr[prev]);
            res%=mod;
        }
        return res;
    }
    for(int j=i;j<arr.size();j++){
        res+=backtracking2(j,deep+1,i,arr);
        res%=mod;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,n;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        long long ans=0;
        cin>>n;
        vector<pair<long long,long long>> prime(n);
        for(int i=0;i<n;i++)
            cin>>prime[i].first>>prime[i].second;
        vector<long long> arr;
        backtracking1(0,1,arr,prime);
        sort(arr.begin(),arr.end());
        // for(auto aa:arr)
        //     cout<<aa<<' ';
        // cout<<endl;
        ans=backtracking2(0,0,-1,arr);
        cout<<"Case "<<cc<<": "<<ans<<endl;
    }
    return 0;
}
*/
// ¥¿¸Ñ
#include <iostream>
using namespace std;

int main() {
	int t, c, k = 0, factor[15], power[15];
	long long n, ans, num[15], prev[15];
	const long long mod = 1000000007;

	cin >> t;
	while (k < t) {
		++k;
		cin >> c;
		for (int i = 0; i < c; ++i)
			cin >> factor[i] >> power[i];
		
		n = 1;
		for (int i = 0; i < c; ++i) {
			num[i] = 1;
			prev[i] = 1;
			for (int j = 0; j < power[i]; ++j) {
				prev[i] = (prev[i] * factor[i]) % mod;
				num[i] = (num[i] + prev[i]) % mod;
			}
			num[i] = (num[i] + (power[i] * prev[i]) % mod) % mod;
			n = (n * prev[i]) % mod;
            cout<<i<<" :"<<num[i]<<' '<<prev[i]<<endl;
		}

		ans = 1;
		for (int i = 0; i < c; ++i)
			ans = (ans * num[i]) % mod;
		ans = (ans + n) % mod;
		cout << "Case " << k << ": " << ans << endl;
	}


	return 0;
}