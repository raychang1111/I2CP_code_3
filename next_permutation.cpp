#include <iostream>
#include <vector>
using namespace std;
void reverse_self(vector<int> &arr,int l,int r){
    while(l<r)
        swap(arr[l++],arr[r--]);
}
int binary_search(int t,vector<int> &arr,int l,int r){
    int res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]>t){
            l=mid+1;
            res=mid;
        }
        else
            r=mid-1;
    }
    while(0<=res-1 && arr[res-1]==arr[res])
        res--;
    return res;
}
void next_permutation_self(vector<int> &arr){   
    bool tag=false;
    for(int i=arr.size()-1;!tag && i>0;i--){
        if(arr[i-1]<arr[i]){
            int index=binary_search(arr[i-1],arr,i,arr.size()-1);
            swap(arr[i-1],arr[index]);
            reverse_self(arr,i,arr.size()-1);
            tag=true;
        }
    }
    if(!tag)
        reverse_self(arr,0,arr.size()-1);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        next_permutation_self(arr);
    for(int aa:arr)
        cout<<aa<<' ';
    cout<<endl;
    return 0;
}