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
bool found = false;

void dfs(int si, int sj)
{
    if (grid[si][sj] == 'B')
    {
        found = true;
        return;
    }
    else
    {
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
}

int main()
{

    cin >> r >> c;
    int sr, sc;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
        }
    }

    dfs(sr, sc);

    if (found)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}