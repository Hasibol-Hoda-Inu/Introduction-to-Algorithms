#include<bits/stdc++.h>
using namespace std;

bool re(long long n){
    if(n == 1)
        return true;
    if(n < 1)
        return false;
   
    bool path1 = false;
    if(n%10 == 0)
        path1 = re(n/10);

    bool path2 = false;
    if(n%20 == 0)
        path2 = re(n/20);
    
    return path1 || path2;
}


int main(){
    int t; cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if(re(n))
            cout << "YES\n";
        else
            cout << "NO\n";
            
    }
    
    return 0;
}