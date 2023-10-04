// 離散化
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={100,9,77,55,21,37,46,81};
    cout<<"離散化前"<<endl;
    for(auto a:arr)
        cout<<a<<' ';
    cout<<endl;
    /////////////////////////////////////////////////////////////////////////
    vector<int> temp;
    temp=arr;
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    for(int i=0;i<arr.size();i++)
        arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
    /////////////////////////////////////////////////////////////////////////
    cout<<"離散化後"<<endl;
    for(auto a:arr)
        cout<<a<<' ';
    cout<<endl;
    return 0;
}