// °f§Ç¼Æ¹ï
#include <bits/stdc++.h>
using namespace std;
int arr[1000007];
int temp[1000007];
long long  merge_sort(int l,int r){
    if(l==r)
        return 0;
    int mid=(l+r)/2;
    long long res=merge_sort(l,mid)+merge_sort(mid+1,r);
    for(int i=l,ptr1=l,ptr2=mid+1;i<=r;i++){
        if(ptr1>mid)
            temp[i]=arr[ptr2++];
        else if(ptr2>r)
            temp[i]=arr[ptr1++];
        else if(arr[ptr1]<=arr[ptr2])
            temp[i]=arr[ptr1++];
        else {
            temp[i]=arr[ptr2++];
            res+=(mid-ptr1+1);
        }
    }
    for(int i=l;i<=r;i++)
        arr[i]=temp[i];
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<merge_sort(0,n-1)<<'\n';
    }
    return 0;
}