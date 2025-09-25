#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[100005];
vector<long long> dis[100005];

void dijkstra(int src){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    dis[src][0] = 0;
    while (!pq.empty())
    {
        pair<long long, int> p = pq.top();
        pq.pop();

        int pn = p.second;
        long long pd = p.first;
        if(dis[pn][k-1] < pd)
            continue;

        for(auto child : adj[pn]){ 
            int child_node = child.first;
            int child_dis = child.second;
            
            if(pd + child_dis < dis[child_node][k-1]){
                dis[child_node][k-1] = pd + child_dis;
                pq.push({dis[child_node][k-1], child_node});
                sort(dis[child_node].begin(), dis[child_node].end());
            }
        }
    }
    
}

int main(){
    
    cin >> n >> m >> k;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    for(int i=1; i<=n; i++){
        dis[i].resize(k);
        for(int j = 0; j<k; j++)
            dis[i][j] = LLONG_MAX;
    }

    dijkstra(1);
    
    for(auto cost : dis[n])
        cout << cost << " ";

    return 0;
}