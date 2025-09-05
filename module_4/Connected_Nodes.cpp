#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n+1];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> v;
        for (int ans : adj_list[x])
        {
            v.push_back(ans);
        }
        if (!v.empty())
        {
            sort(v.begin(), v.end(), greater<int>());
            for (int y : v)
                cout << y << " ";
        }
        else
            cout << -1;

        cout << endl;
    }

    return 0;
}