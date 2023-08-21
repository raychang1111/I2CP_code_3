// https://www.luogu.com.cn/problem/P1706
#include <iostream>
#include <vector>
#include <iomanip>
#define endl '\n'
using namespace std;
void backtracking(int &run,vector<int> &path,const int &n){
    if(path.size()==n){
        for(int pp:path)
            cout<<setw(5)<<pp;
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if((run>>i)&1)
            continue;
        run|=(1<<i);
        path.push_back(i);
        backtracking(run,path,n);
        path.pop_back();
        run&=~(1<<i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,run=0;
    cin>>n;
    vector<int> path;
    backtracking(run,path,n);
    return 0;
}