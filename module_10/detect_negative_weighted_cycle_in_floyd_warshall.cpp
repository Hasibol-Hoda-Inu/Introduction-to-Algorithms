#include <bits/stdc++.h>
using namespace std;
int adj_mat[101][101];
int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; if undirected;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    bool cycle = false;
    for(int i = 0; i<n; i++)
        if(adj_mat[i][i] < 0)
            cycle = true;

    if(cycle)
        cout << "cycle detected";
    else
        cout << "don't have cycle";

    return 0;
}