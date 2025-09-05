#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[101];
vector<Edge> edge_list;
int n, e;
void bellmen_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        int c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "negative weighted cycle detected";
    else
    { 
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i];
            cout << endl;
        }
    }
}

int main()
{

    cin >> n >> e;

    while (e--)
    { // O(e)
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++) // O(n)
        dis[i] = INT_MAX;

    dis[0] = 0;

    bellmen_ford();

    return 0;
}