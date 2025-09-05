#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    int ans = 0;
    if(x+y > 12)
        ans = (x+y)-12;
    else if(x+y <= 12)
        ans = x+y;

    cout << ans;
    return 0;
}