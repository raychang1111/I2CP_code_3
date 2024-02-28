// https://www.luogu.com.cn/problem/P2234       營業額統計
// 經濟管理學上定義了一種最小波動值來衡量這種情況：當最小波動值越大時，就表示營業情況越不穩定
// 定義: 一天的最小波動值=min{∣該天以前某一天的營業額-這天營業額∣}
// 第一天的最小波動值為第一天的營業額
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0,k,temp;
    cin>>n;
    multiset<int> S;
    for(int i=0;i<n;i++){
        cin>>k;
        temp=INT_MAX;
        multiset<int>::iterator itr=S.insert(k);      //SLT用法可以記一下
        if(itr!=S.begin()){
            itr--;
            temp=min(temp,abs(k-*itr));
            itr++;
        }
        itr++;
        if(itr!=S.end()){
            temp=min(temp,abs(k-*itr));
        }
        itr--;
        if(temp!=INT_MAX)
            ans+=temp;
        else
            ans+=k;
    }
    cout<<ans<<endl;
    return 0;
}