// https://www.luogu.com.cn/problem/P1827
/*
#include <bits/stdc++.h>    //建樹版
using namespace std;
char backtracking(int l1,int r1,string &inorder,int l2,int r2,string &preorder,vector<vector<char>> &link){
    if(l2==r2){
        return preorder[l2];
    }
    int m1=l1;
    while(m1<=r1 && inorder[m1]!=preorder[l2])
        m1++;
    // (m1-l1)
    // (r1-m1)
    if(l1<=m1-1){
        link[preorder[l2]-'A'].push_back(backtracking(l1,m1-1,inorder,l2+1,l2+(m1-l1),preorder,link));
    }
    if(m1+1<=r1){
        link[preorder[l2]-'A'].push_back(backtracking(m1+1,r1,inorder,l2+1+(m1-l1),r2,preorder,link));
    }
    return preorder[l2];
}
void Postorder_Traversal(char c,vector<vector<char>> &link,string &postorder){
    for(int i=0;i<link[c-'A'].size();i++)
        Postorder_Traversal(link[c-'A'][i],link,postorder);
    postorder+=c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string inorder,preorder;    //中序 前序
    string postorder;
    vector<vector<char>> link(26); 
    cin>>inorder>>preorder;
    backtracking(0,inorder.size()-1,inorder,0,preorder.size()-1,preorder,link);
    Postorder_Traversal(preorder[0],link,postorder);
    cout<<postorder<<'\n';
    return 0;
}
*/
// /*
#include <bits/stdc++.h>    //非建樹版
using namespace std;
void backtracking(int l1,int r1,string &inorder,int l2,int r2,string &preorder,string &postorder){
    if(l2==r2){
        postorder+=preorder[l2];
        return ;
    }
    int m1=l1;
    while(m1<=r1 && inorder[m1]!=preorder[l2])
        m1++;
    if(l1<=m1-1)
        backtracking(l1,m1-1,inorder,l2+1,l2+(m1-l1),preorder,postorder);
    if(m1+1<=r1)
        backtracking(m1+1,r1,inorder,l2+1+(m1-l1),r2,preorder,postorder);
    postorder+=preorder[l2];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string inorder,preorder;    //中序 前序
    string postorder;
    vector<vector<char>> link(26); 
    cin>>inorder>>preorder;
    backtracking(0,inorder.size()-1,inorder,0,preorder.size()-1,preorder,postorder);
    cout<<postorder<<'\n';
    return 0;
}
// */