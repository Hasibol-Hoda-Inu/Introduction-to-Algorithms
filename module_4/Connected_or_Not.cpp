#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (x == y)
        {
            cout << "YES" << endl;
            continue;
        }

        bool found = false;
        for (int val : adj_list[x])
        {
            if (val == y)
            {
                found = true;
                break;
            }
        }

        if(found)   
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}