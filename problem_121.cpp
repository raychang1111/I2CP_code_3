// https://www.luogu.com.cn/problem/B3637   (LIS O(nlogn) )
#include <bits/stdc++.h>
using namespace std;
// ----------------------線段樹+dp 寫法-------------------------------------------------------
int cl(int i){
    return i*2+1;
}
int cr(int i){
    return i*2+2;
}
void update(int i,int index,int val,int l,int r,vector<int> &Segment_tree){
    if(l==r){
        Segment_tree[i]=max(Segment_tree[i],val);
        return ;
    }
    int m=(l+r)/2;
    // cout<<i<<' '<<l<<' '<<r<<'\n';
    if(l<=index && index<=m){
        // cout<<"進1\n";
        update(cl(i),index,val,l,m,Segment_tree);
        
    }
    if(m+1<=index && index<=r){
        // cout<<"進2\n";
        update(cr(i),index,val,m+1,r,Segment_tree);
    }
    Segment_tree[i]=max(Segment_tree[cl(i)],Segment_tree[cr(i)]);
}
int query(int i,int l,int r,int q_l,int q_r,vector<int> &Segment_tree){ //q_l q_r的區間最大
    if(q_l<=l && r<=q_r){
        return Segment_tree[i];
    }
    int m=(l+r)/2,res=0;
    if(q_l<=m){
        res=max(res,query(cl(i),l,m,q_l,q_r,Segment_tree));
    }
    if(m+1<=q_r){
        res=max(res,query(cr(i),m+1,r,q_l,q_r,Segment_tree));
    }
    return res;
}
void main_1(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    unordered_map<int,int> Segment_index;
    vector<int> Segment_tree(4*n,0);
    vector<int> temp=arr;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
        Segment_index[temp[i]]=i;
    vector<int> dp(n);
    int ans=0;
    for(int i=0;i<n;i++){
        int ptr=Segment_index[arr[i]];
        if(ptr!=0)
            dp[i]=query(0,0,n-1,0,ptr-1,Segment_tree)+1;
        else
            dp[i]=1;
        update(0,ptr,dp[i],0,n-1,Segment_tree);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<'\n';
    // update(0,2,9,0,n-1,Segment_tree);
    // for(int i=0;i<Segment_tree.size();i++){
    //     cout<<Segment_tree[i]<<' ';
    // }
    // cout<<endl;
    // cout<<query(0,0,n-1,0,2,Segment_tree)<<endl;

}
// --------------------二分搜----------------------------------------
void main_2(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    vector<int> arr;
    for(int i=0;i<n;i++){
        if(arr.empty() || arr.back()<nums[i]){
            arr.push_back(nums[i]);
        }
        else{
            int ptr=0;
            int l=0,r=arr.size()-1,m;
            while(l<=r){
                m=(l+r)/2;
                if(arr[m]>=nums[i]){
                    r=m-1;
                    ptr=m;
                }
                else{
                    l=m+1;
                }
            }
            arr[ptr]=nums[i];
        }
    }
    cout<<arr.size()<<'\n';
}
int main(){
    // main_1();
    main_2();
    return 0;
}