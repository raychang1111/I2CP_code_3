// https://www.luogu.com.cn/problem/P2234       ��~�B�έp
// �g�ٺ޲z�ǤW�w�q�F�@�س̤p�i�ʭȨӿŶq�o�ر��p�G��̤p�i�ʭȶV�j�ɡA�N�����~���p�V��í�w
// �w�q: �@�Ѫ��̤p�i�ʭ�=min{���ӤѥH�e�Y�@�Ѫ���~�B-�o����~�B��}
// �Ĥ@�Ѫ��̤p�i�ʭȬ��Ĥ@�Ѫ���~�B
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0,k,temp;
    cin>>n;
    multiset<int> S;
    for(int i=0;i<n;i++){
        cin>>k;
        temp=INT_MAX;
        multiset<int>::iterator itr=S.insert(k);      //SLT�Ϊk�i�H�O�@�U
        if(itr!=S.begin()){
            itr--;
            temp=min(temp,abs(k-*itr));
            itr++;
        }
        itr++;
        if(itr!=S.end()){
            temp=min(temp,abs(k-*itr));
        }
        itr--;
        if(temp!=INT_MAX)
            ans+=temp;
        else
            ans+=k;
    }
    cout<<ans<<endl;
    return 0;
}