// https://www.luogu.com.cn/problem/P1160  指標 雙向鏈結串列
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    bool flag;
    int val;
    node *left;
    node *right;
    node(int a=0){
        flag=true;
        val=a;
        left=NULL;
        right=NULL;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,j,k,head=0;
    cin>>n;
    vector<node*> arr(n,NULL);
    arr[head]=new node(1);
    for(int i=1;i<n;i++){
        arr[i]=new node(i+1);
        // cout<<arr[i]->left<<' '<<arr[i]->right<<'\n';
        cin>>j>>k;
        j--;
        if(k){  //放j的右邊
            if(arr[j]->right){
                arr[i]->right=arr[j]->right;
                arr[j]->right->left=arr[i];
            }
            arr[j]->right=arr[i];
            arr[i]->left=arr[j];
        }
        else{
            if(j==head)
                head=i;
            if(arr[j]->left){
                arr[i]->left=arr[j]->left;
                arr[j]->left->right=arr[i]; 
            }
            arr[j]->left=arr[i];
            arr[i]->right=arr[j];
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>j;
        j--;
        arr[j]->flag=false;
    }
    node* ans=arr[head];
    while(ans){
        if(ans->flag)
            cout<<ans->val<<' ';
        ans=ans->right;
    }
    return 0;
}