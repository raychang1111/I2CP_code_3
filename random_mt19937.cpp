#include <bits/stdc++.h>
// #include <ctime>
using namespace std;
mt19937 gen((unsigned long long)(new char));
mt19937 gen1(time(0));
int main(){
    cout<<gen()%5<<endl;
    cout<<gen1()%5<<endl;
    return 0;
}