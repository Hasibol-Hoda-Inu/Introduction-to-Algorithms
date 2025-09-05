#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        bool can_arrange = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (v[i] == v[j])
                {
                    can_arrange = true;
                    break;
                }
            }
        }

        if (can_arrange)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}