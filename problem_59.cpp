// https://vjudge.net/problem/UVA-512           白癡題 純靠STL
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void print(vector<vector<int>> &arr){
    cout<<"--------------------"<<endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=0,n,m,p,c;
    string s;
    while(cin>>n>>m && n!=0 &&m!=0){
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr[i][j]=(i)*m+j;
        // print(arr);
        cin>>p;
        while(p--){
            cin>>s;
            if(s=="DR"){
                cin>>c;
                vector<int> a(c);
                for(int i=0;i<c;i++)
                    cin>>a[i];
                sort(a.begin(),a.end());
                for(int i=a.size()-1;i>=0;i--)     //橫的
                    arr.erase(arr.begin()+a[i]-1);
            }
            else if(s=="DC"){
                cin>>c;
                vector<int> a(c);
                for(int i=0;i<c;i++)
                    cin>>a[i];
                sort(a.begin(),a.end());
                for(int i=a.size()-1;i>=0;i--)     //直的
                    for(int j=0;j<arr.size();j++)
                        arr[j].erase(arr[j].begin()+a[i]-1);
            }
            else if(s=="IC"){
                cin>>c;
                vector<int> a(c);
                for(int i=0;i<c;i++)
                    cin>>a[i];
                sort(a.begin(),a.end());
                for(int i=a.size()-1;i>=0;i--) 
                    for(int j=0;j<arr.size();j++)
                        arr[j].insert(arr[j].begin()+a[i]-1,-1);
            }
            else if(s=="IR"){
                cin>>c;
                vector<int> a(c);
                for(int i=0;i<c;i++)
                    cin>>a[i];
                sort(a.begin(),a.end());
                for(int i=a.size()-1;i>=0;i--) 
                    arr.insert(arr.begin()+a[i]-1,vector<int>(arr[0].size(),-1));
            }
            else if(s=="EX"){
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                swap(arr[x1-1][y1-1],arr[x2-1][y2-1]);
            }
            // print(arr);
        }
        t++;
        if(t!=1)
            cout<<endl;
        cout<<"Spreadsheet #"<<t<<endl;
        cin>>p;
        while(p--){
            int x,y;
            bool flag=false;
            cin>>x>>y;
            for(int i=0;!flag && i<arr.size();i++){
                for(int j=0;!flag && j<arr[i].size();j++){
                    if(arr[i][j]==(x-1)*m+y-1){
                        cout<<"Cell data in ("<<x<<","<<y<<") moved to ("<<i+1<<","<<j+1<<")"<<endl;
                        flag=true;
                    }
                }
            }
            if(!flag){
                cout<<"Cell data in ("<<x<<","<<y<<") GONE"<<endl;
            }
        }
    }   

    return 0;
}