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
/*  �U�Ъ���


int failure[MXN];  //�x�s�H��i�Ӭ������������ۦP�e����
void KMP(string s, string w){
    // i ���r�� s ��e index, j ���r�� w �H�ǰt�쪺 index
    for(int i = 0,j = -1; i < s.size(); ++i){
        while(j >= 0 && s[i] != w[j+1]){ // ��ǰt���ѧ�즸���ۦP�e����A���ʦr��W
            j = failure[j];
        }
        if(s[i] == w[j+1]){ // ��r���۵�
            ++j;
        }
        if(j+1 == w.size()){ //  ��r�꧹���ǰt
            ans.push_back(i-w.size()+1); // �[�i����
            j = failure[j]; // ���ʦr��W
}}}
int failure[MXN];
void build_failure(string& w){
    for(int i=1,j=fauilre[0]=-1;i<w.size();i++){
        while(j>=0 && w[i] != w[j+1]){ //���ۦP�L�k�ǰt
            j = failure[j];
        }
        if(w[i] == w[j+1]){ // �p�G�i�H�[�����סA�h���e�@�ӵ���+1
            ++j;
        }
        failure[i] = j; // ��������
    }
}
*/