// https://www.luogu.com.cn/problem/P5937
#include <bits/stdc++.h>                //前墜和 種類併查集 離散化
#define endl '\n'
using namespace std;
class interval{         //間隔
public:
    int l,r;
    bool m;
    interval(){
        l=0,r=0,m=false;
    }
};  
int set_find(int x,vector<int> &disjoint_set){
    return disjoint_set[x]=(disjoint_set[x]==x ? x:set_find(disjoint_set[x],disjoint_set));
}
void set_union(int x,int y,vector<int> &disjoint_set){
    x=set_find(x,disjoint_set);
    y=set_find(y,disjoint_set);
    if(x!=y)
        disjoint_set[y]=x;
}
int main(){                 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    string s1;
    cin>>n>>m;
    vector<interval> data(m,interval());
    vector<int> temp(2*m);
    for(int i=0;i<m;i++){
        cin>>data[i].l>>data[i].r;
        cin>>s1;
        data[i].l--;
        data[i].m=(s1=="odd");
        temp[i*2]=data[i].l;
        temp[i*2+1]=data[i].r;
    }
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    // lower_bound(temp.begin(),temp.end(),val)-temp.begin();
    vector<int> disjoint_set(2*temp.size());
    for(int i=0;i<disjoint_set.size();i++)
        disjoint_set[i]=i;
    int ans=m;
    for(int i=0;i<m;i++){
        data[i].l=lower_bound(temp.begin(),temp.end(),data[i].l)-temp.begin();
        data[i].r=lower_bound(temp.begin(),temp.end(),data[i].r)-temp.begin();
        if(data[i].m){      // 奇數 敵
            if(set_find(data[i].l,disjoint_set) == set_find(data[i].r,disjoint_set)){
                ans=i;
                break;
            }
            set_union(data[i].l,data[i].r+temp.size(),disjoint_set);
            set_union(data[i].l+temp.size(),data[i].r,disjoint_set);
        }
        else{               // 偶數 友
            if(set_find(data[i].l,disjoint_set) == set_find(data[i].r+temp.size(),disjoint_set)){
                ans=i;
                break;
            }
            set_union(data[i].l,data[i].r,disjoint_set);
            set_union(data[i].l+temp.size(),data[i].r+temp.size(),disjoint_set);
        }
    }
    cout<<ans<<endl;
    return 0;
}