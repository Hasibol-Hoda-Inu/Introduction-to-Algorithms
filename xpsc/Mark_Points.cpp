#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >>n;
    string s;
    cin >> s;
    int cnt = 0;
    bool flag = true;
    
    for(int i = 0; i<n; i++){
        if(s[i] == '1')
            cnt++;
        else{
            if(cnt == 1 || cnt == 2){
                flag = false;
                break;
                
            }
            cnt = 0;
        }
    }
    
    if(cnt == 1 || cnt == 2)
        flag = false;
    
    if(flag)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {

    int t; cin >> t;
    while(t--){
        solve();
    }
}
