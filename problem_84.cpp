// https://www.luogu.com.cn/problem/P1449   ¦Z?ªí?¦¡­pºâ
#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    int number=0;
    stack<int> st;
    while(cin>>c && c!='@'){
        if('0'<=c && c<='9'){
            number=number*10+c-'0';
        }
        else if(c=='.'){
            st.push(number);
            number=0;
        }
        else{
            if(c=='+'){
                int temp=st.top();
                st.pop();
                temp+=st.top();
                st.pop();
                st.push(temp);
            }
            if(c=='-'){
                int temp=-st.top();
                st.pop();
                temp+=st.top();
                st.pop();
                st.push(temp);
            }
            if(c=='*'){
                int temp=st.top();
                st.pop();
                temp*=st.top();
                st.pop();
                st.push(temp);
            }
            if(c=='/'){
                int temp=st.top();
                st.pop();
                temp=st.top()/temp;
                st.pop();
                st.push(temp);
            }
        }
    }
    cout<<st.top()<<'\n';
    return 0;
}