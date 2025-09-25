#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t, sx, sy, ex, ey, cnt = 0;
    cin >> t >> sx >> sy >> ex >> ey;
    while (t--)
    {
        if(sx == ex && sy == ey)
            break;
        char c; 
        cin >> c;

        if(c == 'E' && sx < ex)
            sx++;
        if(c == 'S' && sy > ey)
            sy--;
        if(c == 'W' && sx > ex)
            sx--;
        if(c == 'N' && sy < ey)
            sy++;
        
        cnt++;
    }

    if(sx == ex && sy == ey)
        cout << cnt;
    else
        cout << -1;
    

    return 0;
}