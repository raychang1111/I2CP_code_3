// https://www.luogu.com.cn/problem/P1032       //非正解因測資薄弱 複雜度爆掉了 優化可寫 雙向BFS
#include <bits/stdc++.h>
using namespace std;
int bfs(string &start,string &end,vector<pair<string,string>> &rule){
    set<string> SET;
    queue<pair<string,int>> Q;
    Q.push({start,0});
    SET.insert(start);
    while(!Q.empty()){
        // cout<<Q.front().first<<'\n';
        if(Q.front().first==end)
            return Q.front().second;
        for(int i=0;i<rule.size();i++){
            for(int j=0;j<Q.front().first.size();j++){
                bool flag=true;
                for(int k=0;flag && k<rule[i].first.size();k++)
                    flag=(j+k<Q.front().first.size() && Q.front().first[j+k]==rule[i].first[k]);
                if(flag){
                    int k=0;
                    string temp;
                    while(k<j){
                        temp+=Q.front().first[k];
                        k++;
                    }
                    temp+=rule[i].second;
                    j+=rule[i].first.size()-1;
                    k=j+1;
                    while(k<Q.front().first.size()){
                        temp+=Q.front().first[k];
                        k++;
                    }
                    if(Q.front().second+1<=10 && !SET.count(temp)){
                        Q.push({temp,Q.front().second+1});
                        SET.insert(temp);
                    }
                }
            }
            
        }
        Q.pop();
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string start,end,s1,s2;
    vector<pair<string,string>> rule;
    cin>>start>>end;
    while(cin>>s1){
        cin>>s2;
        rule.push_back({s1,s2});
    }
    int ans=bfs(start,end,rule);
    if(ans==-1)
        cout<<"NO ANSWER!\n";
    else
        cout<<ans<<'\n';
    return 0;
}