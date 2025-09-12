#include<bits/stdc++.h>
using namespace std;

void re(long long n){
    if(n == 0)
        return;
    re(n/10);
    cout << n%10 << " ";
}

int main(){
    long long t; cin >> t;

    while (t--)
    {
        long long n; cin >> n;
        if(n == 0) 
            cout << 0;
        else
            re(n);
        
        cout << endl;
    }
    
    return 0;
}