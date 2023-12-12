// https://vjudge.net/contest/555030#problem/D
#include <bits/stdc++.h>
using namespace std;
void kmp_init(string &w,vector<int> &w_prev){
    w_prev[0]=-1;
    for(int i=1,j=0;i<w.size();i++){
        while(j!=0 && w[j]!=w[i]){          //EX: abcabdabcabcabd
            j=w_prev[j-1]+1;
        }
        if(w[j]==w[i]){
            w_prev[i]=j;
            j++;
        }
        else{
            j=0;
            w_prev[i]=-1;
        }
    }
}
int KMP(string &s,string &w,vector<int> &w_prev){
    int res=0;
    for(int i=0,j=0;i<s.size();i++){
        // cout<<i<<"-------------"<<j<<endl;
        // cout<<"j: ";
        while(j!=0 && s[i]!=w[j]){
            j=w_prev[j-1]+1;
            // cout<<j<<' ';
        }
        // cout<<endl;
        if(s[i]==w[j]){
            j++;
        }
        if(j==w.size()){
            // cout<<i-w.size()+1<<endl;
            res++;
            j=w_prev[j-1]+1;
        }
    }
    return res;
}
int main(){
    string s;
    string w;
    cin>>s>>w;
    vector<int> w_prev(w.size());
    kmp_init(w,w_prev);
    for(int i=0;i<w_prev.size();i++)
        cout<<w_prev[i]<<' ';
    cout<<endl;
    cout<<KMP(s,w,w_prev)<<endl;
    return 0;
}
/*  助教版本


int failure[MXN];  //儲存以第i個為結尾的次長相同前綴後綴
void KMP(string s, string w){
    // i 為字串 s 當前 index, j 為字串 w 以匹配到的 index
    for(int i = 0,j = -1; i < s.size(); ++i){
        while(j >= 0 && s[i] != w[j+1]){ // 當匹配失敗找到次長相同前綴後綴，移動字串W
            j = failure[j];
        }
        if(s[i] == w[j+1]){ // 當字元相等
            ++j;
        }
        if(j+1 == w.size()){ //  當字串完全匹配
            ans.push_back(i-w.size()+1); // 加進答案
            j = failure[j]; // 移動字串W
}}}
int failure[MXN];
void build_failure(string& w){
    for(int i=1,j=fauilre[0]=-1;i<w.size();i++){
        while(j>=0 && w[i] != w[j+1]){ //當不相同無法匹配
            j = failure[j];
        }
        if(w[i] == w[j+1]){ // 如果可以加長長度，則為前一個答案+1
            ++j;
        }
        failure[i] = j; // 紀錄答案
    }
}
*/