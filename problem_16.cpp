// https://www.luogu.com.cn/problem/P1157
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void backtracking(vector<int> &path,int run,const int &n,const int &r){
    if(path.size()==r){
        for(int pp:path)
            cout<<setw(3)<<pp;
        cout<<endl;
        return ;
    }
    for(int i=run;i<=n;i++){
        path.push_back(i);
        backtracking(path,i+1,n,r);
        path.pop_back();    
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,r;
    cin>>n>>r;
    vector<int> path;
    backtracking(path,1,n,r);
    return 0;
}