// https://www.luogu.com.cn/problem/P3817   �g��
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,x,ans=0,temp;
    cin>>n>>x;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i+1<arr.size();i++){
        //�p�G�ڭ̦Y���Ĥ@�Ӹ̪��A�u�|��֤@�Ӥ��ժ��q�A
        //�Ӧp�G�Y���ĤG�Ӹ̪��A�i�H���2�Ӥ��ժ��q�C 
        //�ҥH�ڭ̭n�ɶq�Y���ĤG�Ӹ̪��}�G
        temp=arr[i]+arr[i+1]-x;
        if(temp<=0)
            continue;
        ans+=temp;
        if(arr[i+1]<temp){
            temp-=arr[i+1];
            arr[i+1]=0;
            arr[i]-=temp;
        }
        else
            arr[i+1]-=temp;
    }
    cout<<ans<<endl;
    return 0;
}