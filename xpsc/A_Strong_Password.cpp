#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--)
    {
        string str; 
        cin >> str;
        int i;
        for(i = 1; i<str.size(); i++)
            if(str[i] == str[i-1])
                break;
        if(str[i-1] == 'a')
            str.insert(str.begin() + i, 'b');
        else
            str.insert(str.begin() + i, 'a');
        
        cout << str << endl;
    }
    
    return 0;
}