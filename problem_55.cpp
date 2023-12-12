// https://vjudge.net/problem/UVA-11576
/*  暴力算法
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
*/
//加入KMP算法
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void KMP_init(vector<vector<char>> &data,vector<vector<int>> &data_prev){
    for(int i=0;i<data.size();i++){
        data_prev[i][0]=-1;
        for(int j=1,k=0;j<data[i].size();j++){
            while(k>0 && data[i][k]!=data[i][j]){
                k=data_prev[i][k-1]+1;
            }
            if(data[i][k]==data[i][j]){
                data_prev[i][j]=k;
                k++;
            }
            else
                data_prev[i][j]=-1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,w;
    cin>>n;
    while(n--){
        cin>>k>>w;
        string ans;
        vector<vector<char>> data(w,vector<char>(k));
        vector<vector<int>> data_prev(w,vector<int>(k));        //次長相同前墜後墜
        for(int i=0;i<w;i++)
            for(int j=0;j<k;j++)
                cin>>data[i][j];
        KMP_init(data,data_prev);
        for(int i=0;i<k;i++)    
            ans+=data[0][i];
        for(int i=1;i<w;i++){
            int j,k;
            for(j=0,k=0;j<ans.size();j++){
                while(k>0 && ans[j]!=data[i][k]){
                    k=data_prev[i][k-1]+1;
                }
                if(ans[j]==data[i][k]){
                    k++;
                }
                if(k==data[i].size()){
                    break;
                }
            }
            if(k<data[i].size()){
                for(int X=k;X<data[i].size();X++)
                    ans+=data[i][X];
            }
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}
