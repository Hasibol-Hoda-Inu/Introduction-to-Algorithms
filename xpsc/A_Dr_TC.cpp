#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s;
        cin >> s;
        int ones = 0;

        for(char c : s)
            if(c == '1')
                ones++;
        int sum = 0;
        for(char c : s)
            if(c == '1')
                sum+= ones-1;
            else
                sum+= ones+1;

        cout << sum << endl;
    }
    
    return 0;
}