// https://vjudge.net/problem/UVA-11175
#include <bits/stdc++.h>            //想法很難  實作暴搜很簡單
using namespace std;
int main(){
    int N,m,k,x,y;
    cin>>N;
    for(int cases=1;cases<=N;cases++){
        cin>>m>>k;
        vector<vector<bool>> path(m,vector<bool>(m,false));
        for(int i=0;i<k;i++){
            cin>>x>>y;
            path[x][y]=true;
        }
        bool br=false;
        for(int i=0;i<m && !br;i++){
            for(int j=0;j<m && !br;j++){
                bool b1=false,b2=false;
                for(int k=0;k<m;k++){
                    if(path[i][k] && path[j][k]) 
                        b1=true;
                    if(path[i][k] ^ path[j][k]) 
                        b2=true;
                }
                if(b1 && b2)
                    br=true;
            }
        }
        if(!br)
            cout<<"Case #"<<cases<<": Yes"<<endl;
        else
            cout<<"Case #"<<cases<<": No"<<endl;
    }
    return 0;
}