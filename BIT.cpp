// https://vjudge.net/contest/540241#problem/A
// (�� ? ���x�s���϶����׬� 2^(p���G�i����s�ƶq) �۷��p���̥k��1����m���̶i���)
//                          =>    lowbit(x) �Y����e��m x ���x�s���϶�����
#include <bits/stdc++.h>
#define int long long
using namespace std;
class BIT{  //base 1
public:
    int lowbit(int x){
        return x&-x;
    }
    vector<int> arr;
    BIT(int n){
        arr=vector<int>(n+1,0);
    }
    int query(int r){
        int res=0;
        while(r){
            res+=arr[r];
            r-=lowbit(r);
        }
        return res;
    }
    void update(int i,int val){  //�[�Wval
        while(i<arr.size()){
            arr[i]+=val;
            i+=lowbit(i);
        }
    }
    int query_interval(int l,int r){    //base 1
        return query(r)-query(l-1);
    }
};
signed main(){
    int n,q,a,b,c;
    cin>>n>>q;
    BIT bit_tree(n);
    for(int i=0;i<n;i++){
        cin>>a;
        bit_tree.update(i+1,a);
    }
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        if(a==1)
            bit_tree.update(b,c);
        else{
            cout<<bit_tree.query_interval(b,c)<<'\n';
        }
    }
    return 0;
}