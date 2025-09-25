#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--)
    {
        long long l,r;
        cin >> l >> r;
        long long mn_value = min(l, r);
        long long mx_value = max(l, r);
        l = mn_value;
        r = mx_value;
        
        long long sum = (r*(r+1) - l*(l-1))/2;
        cout << sum << endl;
    }
    
    return 0;
}