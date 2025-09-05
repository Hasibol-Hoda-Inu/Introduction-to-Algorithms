#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[101];
int dis[101];

void dijkstra(int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int pn = p.second;
        int pd = p.first;


        for(auto child : adj[pn]){ 
            int child_node = child.first;
            int child_dis = child.second;

            if(pd + child_dis < dis[child_node]){
                dis[child_node] = pd + child_dis;
                pq.push({dis[child_node], child_node});
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