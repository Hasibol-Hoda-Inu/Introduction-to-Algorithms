#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        
        long long sum = a+b+c;
        long long di = sum/3;

        if(sum%3 == 0 && b <= di)
            cout << "YES\n";
        else
            cout << "NO\n";
        
    }
    
    return 0;
}