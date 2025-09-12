#include <bits/stdc++.h>
using namespace std;
int n;
char mat[31][31];
bool vis[31][31];
int level[31][31];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}
int cnt = 0;

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        int pi = p.first;
        int pj = p.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + dir[i].first;
            int cj = pj + dir[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
                if (mat[ci][cj] == 'E')
                    return;
            }
        }
    }
}

int main()
{

    while (cin >> n)
    {

        int si, sj, di, dj;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 'S')
                    si = i, sj = j;
                if (mat[i][j] == 'E')
                    di = i, dj = j;
            }
        }

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(si, sj);

        cout << level[di][dj];
    }

    return 0;
}