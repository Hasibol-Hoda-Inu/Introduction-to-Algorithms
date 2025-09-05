#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[101];
int dis[101];

void dijkstra(int src){
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int pn = p.first;
        int pd = p.second;


        for(auto child : adj[pn]){
            int child_node = child.first;
            int child_dis = child.second;

            if(pd + child_dis < dis[child_node]){
                dis[child_node] = pd + child_dis;
                q.push({child_node, dis[child_node]});
            }
        }
    }
    
}

int main(){
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for(int i=0; i<n; i++)
        dis[i] = INT_MAX;

    dijkstra(0);
    
    for(int i = 0; i<n; i++)
        cout << i << " -> " << dis[i] << endl;
return 0;
}