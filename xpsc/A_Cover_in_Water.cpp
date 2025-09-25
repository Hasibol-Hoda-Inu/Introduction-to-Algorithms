#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s;
        cin >> s;

        int cnt = 0;
        int ec = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '.'){
                cnt++;
                ec++;
                if(cnt == 3)
                    break;
            }else
                cnt = 0;
        }

        if(cnt == 3)
            cout << 2 << endl;
        else
            cout << ec << endl;
        
    }
    
    return 0;
}