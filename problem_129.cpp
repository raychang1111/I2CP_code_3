// https://vjudge.net/problem/UVA-941
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n;
    cin>>t;
    string s1,s2;
    vector<long long> nOrder(21);
    nOrder[0]=1;
    for(int i=1;i<=20;i++)
        nOrder[i]=nOrder[i-1]*i;

    while(t--){
        string ans;
        cin>>s1;
        cin>>n;
        
        s2=s1;
        sort(s1.begin(),s1.end());
        
        n%=nOrder[s2.size()];

        // cout<<n<<endl;
        for(long long i=s2.size()-1;i>=0;i--){
            long long temp=n/nOrder[i];
            temp%=s1.size();
            ans+=s1[temp];
            s1.erase(s1.begin()+temp);
            n%=nOrder[i];
        }
        // ans+=s1[0];
        cout<<ans<<endl;
    }

    return 0;
}
// abc 0
// acb 1
// bac 2
// bca 3
// cab 4
// cba 5
// abc 6
