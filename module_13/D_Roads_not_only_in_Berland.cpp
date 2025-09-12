#include <bits/stdc++.h>
using namespace std;

int group_size[1005];
int parent[1005];

int find(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if (parent[leaderA] >= parent[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }

    vector<pair<int, int>> rm;
    int cnt = 0;

    int m = n - 1;
    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = find(a);
        int leaderB = find(b);

        if (leaderA == leaderB)
        {
            rm.push_back({a, b});
            cnt++;
        }
        else
            dsu_union(a, b);
    }

    vector<int> v;

    for (int i = 2; i <= n; i++)
    {
        int leader_1 = find(1);
        int leader_node = find(i);
        if (leader_1 != leader_node)
        {
            dsu_union(leader_1, leader_node);
            v.push_back(leader_node);
        }
    }

    cout << cnt << endl;
    
    for(int i = 0; i<cnt; i++){
        cout << rm[i].first << " " << rm[i].second << " " << 1 << " " << v[i] << endl;
    }
    

    return 0;
}