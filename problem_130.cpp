// https://vjudge.net/problem/UVA-10858             (超級實作必看)
#include <bits/stdc++.h>
using namespace std;
void prime_factorization(int x,multiset<int> &number){
    for(int i=2;i<=sqrt(x)+1;i++){
        while(x%i==0){
            x/=i;     
            number.insert(i);
        }   
    }
    if(x!=1)
        number.insert(x);
}
void marge_number(set<multiset<int>> &ans,multiset<int> &number){
    if(ans.find(number)!=ans.end()){
        return ;
    }
    ans.insert(number);
    if(number.size()==2)
        return ;
    vector<int> temp=vector<int>(number.begin(),number.end());
    for(int i=0;i<temp.size();i++){
        for(int j=i+1;j<temp.size();j++){
            swap(temp[j],temp[temp.size()-1]);
            temp[i]*=temp[temp.size()-1];
            number=multiset<int> (temp.begin(),temp.end()-1);
            marge_number(ans,number);
            temp[i]/=temp[temp.size()-1];
            swap(temp[j],temp[temp.size()-1]);
        }
    }
    number=multiset<int> (temp.begin(),temp.end());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n && n!=0){
        multiset<int> number;
        prime_factorization(n,number);
        set<multiset<int>> ans;
        if(number.size()>=2)
            marge_number(ans,number);
        cout<<ans.size()<<'\n';
        
        for(auto aa:ans){
            bool first=false;
            for(auto a:aa){
                if(first)
                    cout<<' ';
                first=true;
                cout<<a;
            }
            cout<<'\n';
        }
    }
    return 0;
}