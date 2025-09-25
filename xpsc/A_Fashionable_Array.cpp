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
        vector<int> v;

        while (n--)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());
        int cnt = 0;
        int cnt2 = 0;

        int mx = v.back();
        int mn = v[0];

        if (mx % 2 == mn % 2)
            cout << 0 << endl;
        else
        {
            int i = 0;
            while (v[i] % 2 != mx % 2)
            {
                cnt++;
                i++;
            }

            int j = v.size() - 1;
            while (v[j] % 2 != mn % 2)
            {
                cnt2++;
                j--;
            }

            cout << min(cnt, cnt2) << endl;
        }
    }

    return 0;
}