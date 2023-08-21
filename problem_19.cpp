// https://www.luogu.com.cn/problem/P3392
#include <bits/stdc++.h>
using namespace std;
class color{
public:
    int w,b,r;
    color(int i=0,int j=0,int k=0){
        w=i,b=j,r=k;
    }
    int Coloring_w(){
        return b+r;
    }
    int Coloring_b(){
        return w+r;
    }
    int Coloring_r(){
        return w+b;
    }
};
int main(){
    char c;
    int n,m,ans=INT_MAX;
    cin>>n>>m;
    vector<color> graph(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c=='W')
                graph[i].w++;
            else if(c=='B')
                graph[i].b++;
            else
                graph[i].r++;
        }
    }
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            int temp=0;
            for(int x=0;x<n;x++){
                if(x<i)
                    temp+=graph[x].Coloring_w();
                else if(x<j)
                    temp+=graph[x].Coloring_b();
                else
                    temp+=graph[x].Coloring_r();
            }
            ans=min(temp,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}