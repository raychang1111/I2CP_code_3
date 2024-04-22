// https://www.luogu.com.cn/problem/P1020       (重新了解一次 好題)
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int m,l,r,ptr;
    vector<int> nums;
    while(cin>>m)
        nums.push_back(m);
    vector<int> arr;
    arr.push_back(nums[0]);
    vector<int> arr2;
    arr2.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(arr.back()>=nums[i])
            arr.push_back(nums[i]);
        else{
            ptr=0;
            l=0;
            r=arr.size()-1;
            while(l<=r){
                m=(l+r)/2;
                if(arr[m]<nums[i]){
                    ptr=m;
                    r=m-1;
                }
                else
                    l=m+1;
            }
            arr[ptr]=nums[i];
        }
        if(arr2.back()<nums[i])
            arr2.push_back(nums[i]);
        else{
            ptr=0;
            l=0;
            r=arr2.size()-1;
            while(l<=r){
                m=(l+r)/2;
                if(arr2[m]>=nums[i]){
                    ptr=m;
                    r=m-1;
                }
                else
                    l=m+1;
            }
            arr2[ptr]=nums[i];
        }
    }
    // for(int i=0;i<arr2.size();i++)
    //     cout<<arr2[i]<<' ';
    // cout<<'\n';
    cout<<arr.size()<<'\n';
    cout<<arr2.size()<<'\n';
    return 0;
}