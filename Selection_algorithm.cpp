// Selection in expected linear time
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include <bits/stdc++.h>
using namespace std;
int partition_self(vector<int> &arr,int l,int r,int pivot){
    queue<int> q1,q2,q3;
    for(int i=l;i<=r;i++){
        if(arr[i]==pivot)
            q2.push(arr[i]);
        else if(arr[i]>pivot)
            q1.push(arr[i]);
        else
            q3.push(arr[i]);
    }
    int res=q1.size()+q2.size()/2;
    for(int i=l;i<=r;i++){
        if(!q1.empty()){
            arr[i]=q1.front();
            q1.pop();
        }
        else if(!q2.empty()){
            arr[i]=q2.front();
            q2.pop();
        }
        else{
            arr[i]=q3.front();
            q3.pop();
        }
    }
    return res;
}
int Selection_algorithm(vector<int> &arr,int l,int r,int k){        // kptr=k+l-1
    if(l==r)
        return arr[l];
    // for(int i=l;i<=r;i++)
    //     cout<<arr[i]<<' ';
    // cout<<endl;
    int mids=l;
    int ptr=l;
    while(ptr+5<r){
        sort(arr.begin()+ptr,arr.begin()+ptr+5);
        swap(arr[mids++],arr[ptr+2]);
        ptr+=5;
    }
    sort(arr.begin()+ptr,arr.begin()+r+1);
    swap(arr[mids++],arr[ptr+(r-ptr)/2]);
    // for(int i=l;i<=r;i++)
    //     cout<<arr[i]<<' ';
    // cout<<endl;
    // ----------------------------------------------------------------------
    // cout<<"arr :";
    // for(int i=l;i<mids;i++)
    //     cout<<arr[i]<<' ';
    // cout<<endl;
    // ----------------------------------------------------------------------
    int pivot=Selection_algorithm(arr,l,mids-1,(mids-l)/2);
    // cout<<pivot<<endl;
    int m=partition_self(arr,l,r,pivot);
    // cout<<l<<' '<<r<<' '<<m<<' '<<k<<endl;
    if(m+1==k)
        return arr[l+m];
    else if(m+1>k)
        return Selection_algorithm(arr,l,l+m-1,k);
    else
        return Selection_algorithm(arr,l+m+1,r,k-(m+1));
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Selection_algorithm(arr,0,arr.size()-1,t)<<endl;
    return 0;
}