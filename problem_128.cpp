// https://www.luogu.com.cn/problem/P1276
#include <bits/stdc++.h>
using namespace std;
int main(){
    int L,N;
    cin>>L>>N;
    vector<vector<int>> arr(N,vector<int>(3));
    for(int i=0;i<N;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    int ans_1=0,ans_2=0;
    for(int i=0;i<=L;i++){
        int mode=2;
        for(int j=0;j<arr.size();j++){
            if(arr[j][1]<=i && i<=arr[j][2]){
                if(arr[j][0]==0){
                    if(mode==1){
                        ans_2++;
                        ans_1--;
                    }
                    mode=0;
                }
                else{
                    if(mode==0){
                        ans_1++;
                        mode=1;
                    }
                }
            }
        }
    }
    cout<<ans_1<<'\n'<<ans_2<<'\n';
    return 0;
}
// 0 1 2 3 4 5 6 7 8 9 10
// 0 1           7 8 9 10
// 0 1 x x x x x 7 8 9 10
// 0 1 x x x       8 9 10