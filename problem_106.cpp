// https://www.luogu.com.cn/problem/P4715
#include <bits/stdc++.h>
using namespace std;
int d_and_c(int l,int r,vector<int> &nums){
    if(l==r)
        return l;
    int m=(l+r)/2,win1,win2;
    win1=d_and_c(l,m,nums);
    win2=d_and_c(m+1,r,nums);
    if(nums[win1]>nums[win2])
        return win1;
    return win2;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(1<<n);
    for(int i=0;i<nums.size();i++)
        cin>>nums[i];
    int m=(nums.size()-1)/2,win1,win2;
    win1=d_and_c(0,m,nums);
    win2=d_and_c(m+1,nums.size()-1,nums);
    if(nums[win1]>nums[win2])
        cout<<win2+1;
    else
        cout<<win1+1;
    cout<<'\n';
    return 0;
}