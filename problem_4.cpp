// https://www.luogu.com.cn/problem/P1024
// ¼É¤O
/*
#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
int main(){
    cin>>a>>b>>c>>d;
    double x=-100;
    while(x<=100){
        if(abs(f(x))<0.0000001){
            cout<<fixed<<setprecision(2)<<x<<' ';
            x+=1;
        }
        else
            x+=0.01;
    }
    return 0;
}
*/
// ¤û¹yªk¨D®Ú
#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
double df(double x){
    return 3*a*x*x+2*b*x+c;
}
bool same(double x,double y){
    return abs(x-y)<0.000001;
}
double Newton_Method(double xn){
    double new_x=xn-f(xn)/df(xn);
    if(same(f(new_x),0))
        return new_x;
    else
        return Newton_Method(new_x);
}
int main(){
    cin>>a>>b>>c>>d;
    vector<double> ans;
    for(int i=-100;i<=100;i++){
        double temp=Newton_Method(i);
        bool tag=false;
        for(int i=0;i<ans.size();i++){
            if(same(temp,ans[i])){
                tag=true;
                break;
            }
        }
        if(!tag)
            ans.push_back(temp);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<fixed<<setprecision(2)<<ans[i]<<' ';
    cout<<endl;
    return 0;
}