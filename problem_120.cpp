// https://www.luogu.com.cn/problem/P1908 (逆序數對 小心爆int)
#include <bits/stdc++.h>
#define int long long
using namespace std;
// -------------------------------------------------
long long marge_sort(int l,int r,vector<int> &arr){
    if(l==r)
        return 0;
    int m=(l+r)/2;
    long long res=0;
    res+=marge_sort(l,m,arr);
    res+=marge_sort(m+1,r,arr);
    int ptr1=l,ptr2=m+1;
    vector<int> temp(r-l+1);
    for(int i=0;i<temp.size();i++){
        if(ptr1<=m && ptr2<=r){
            if(arr[ptr1]>arr[ptr2]){
                res+=m-ptr1+1;
                temp[i]=arr[ptr2];
                ptr2++;
            }
            else{
                temp[i]=arr[ptr1];
                ptr1++;
            }
        }
        else if(ptr1<=m){
            temp[i]=arr[ptr1];
            ptr1++;
        }
        else {
            temp[i]=arr[ptr2];
            ptr2++;
        }
    }
    for(int i=0;i<temp.size();i++){
        arr[l+i]=temp[i];
    }
    return res;
}
void main_1(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<marge_sort(0,arr.size()-1,arr)<<'\n';
}
// ------------------------------------------------------------
class BIT{
public:
    vector<int> BIT_tree;
    int lowbit(int x){
        return x&-x;
    }
    BIT(int n){
        BIT_tree=vector<int>(n+1,0);
    }   
    int query(int x){
        int res=0;
        while(x){
            res+=BIT_tree[x];
            x-=lowbit(x);
        }
        return res;
    }
    void update(int i,int val){
        while(i<BIT_tree.size()){
            BIT_tree[i]+=val;
            i+=lowbit(i);
        }
    }
};
void main_2(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int> temp=arr;
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    for(int i=0;i<n;i++){
        arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()+1;
        // cout<<arr[i]<<' ';
    }
    int ans=0;
    BIT bit_tree(n);
    for(int i=arr.size()-1;i>=0;i--){
        bit_tree.update(arr[i],1);
        ans+=bit_tree.query(arr[i]-1);
    }
    cout<<ans<<'\n';
}
// -------------------------------------------------------------
signed main(){
    // main_1();
    main_2();
    return 0;
}