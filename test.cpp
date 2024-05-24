#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="abc";
    for(int i=0;i<3;i++)
        next_permutation(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
} 