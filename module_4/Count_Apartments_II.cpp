#include <bits/stdc++.h>
using namespace std;
int r, c;
char grid[1001][1001];
bool visited[1001][1001];
vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool is_valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}

int cnt = 0;
vector<int> v;

void dfs(int si, int sj)
{
    cnt++;
    visited[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        // cout << ci << " " << cj << endl;
        if (is_valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j] && grid[i][j] != '#')
            {
                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(v.begin(), v.end());

    if(v.empty())
        cout << 0;
    else{
        for(int ans : v)
            cout << ans << " ";
    }
        

    return 0;
}