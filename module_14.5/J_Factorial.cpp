#include<bits/stdc++.h>
using namespace std;

long long re(long long n){
    if(n == 0)
        return 1;
    return n*=re(n-1);
}

int main(){
    long long n; cin >>n;
    cout << re(n);
    return 0;
}