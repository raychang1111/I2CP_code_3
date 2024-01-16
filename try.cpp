#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
void init_self(vector<pair<int,int>> &arr,vector<int> &f,vector<int> &index,priority_queue<int,vector<int>,greater<int>> &pq,vector<int> &f_sum){
    int i=0,j=1;
    while(i<arr.size()){
        if(pq.empty() || arr[i].first<=pq.top()){
            index[j]=arr[i].first;
            f[j]=f[j-1]+1;
            pq.push(arr[i].second);
            i++;
        }
        else{
            index[j]=pq.top();
            f[j]=f[j-1]-1;
            pq.pop();
        }
        f_sum[j]=f_sum[j-1]+(f[j-1]*(index[j]-index[j-1]));
        j++;
    }
    while(!pq.empty()){
        index[j]=pq.top();
        f[j]=f[j-1]-1;
        pq.pop();
        f_sum[j]=f_sum[j-1]+(f[j-1]*(index[j]-index[j-1]));
        j++;
    }
    while(j<f_sum.size()){
        f_sum[j]=f_sum[j-1];
        index[j]=index[j-1];
    }
}
int B_S(vector<int> &index,int val){
    int res=0,l=0,r=index.size()-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(index[mid]<=val){
            l=mid+1;
            res=mid;
        }
        else
            r=mid-1;
    }
    return res;
}
void main_1(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,x;
    cin>>n>>m;
    vector<pair<int,int>> arr(n);
    vector<int> f(2*n+1,0);     //1
    vector<int> f_sum(2*n+1,0);
    vector<int> index(2*n+1,0); //1
    for(int i=0;i<n;i++)
        cin>>arr[i].first;
    for(int i=0;i<n;i++)
        cin>>arr[i].second;
    sort(arr.begin(),arr.end(),cmp);
    priority_queue<int,vector<int>,greater<int>> pq;
    init_self(arr,f,index,pq,f_sum);
    while(m--){
        cin>>x;
        if(index.back()<x)
            cout<<f_sum.back();
        else{
            int i=B_S(index,x);
            cout<<f_sum[i]+f[i]*(x-index[i]);
        }
        cout<<(m==0? '\n':' ');
    }
    // return 0;
}
int main(){
    vector<vector<int>> a;
    a.push_back({1});
    cout<<a[0][0]<<endl;
    return 0;
}