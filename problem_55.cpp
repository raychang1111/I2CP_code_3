// https://vjudge.net/problem/UVA-11576
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,w;
    cin>>n;
    while(n--){
        cin>>k>>w;
        string ans;
        vector<string> arr(w);
        for(int i=0;i<w;i++)
            cin>>arr[i];
        ans=arr[0];
        for(int i=1;i<w;i++){
            int add_s=0;
            for(int j=0;j<ans.size();j++){
                int temp_j=j,temp=0;
                while(ans[temp_j]==arr[i][temp]){
                    temp_j++;
                    temp++;
                    if(temp_j>=ans.size() || temp>=k)
                        break;
                }
                if(temp>=k){
                    add_s=temp;
                    break;
                }
                if(temp_j>=ans.size())
                    add_s=max(add_s,temp);
            }
            ans+=(arr[i].substr(add_s,k-add_s));
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}
