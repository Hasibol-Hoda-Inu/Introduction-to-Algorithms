#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, ll>> adj[100005];
ll dis[100005];
ll parent[100005];

void dijkstra(ll src){
    priority_queue<pair<ll, ll>, vector<pair<ll , ll>>, greater<pair<ll , ll>> >pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        ll p_node = p.second;
        ll pd = p.first;

        for(auto child : adj[p_node]){
            ll child_node = child.first;
            ll child_dis = child.second;

            if(child_dis + pd < dis[child_node]){
                dis[child_node] = child_dis + pd;
                pq.push({dis[child_node], child_node});
                parent[child_node] = p_node;
            }

        }
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(ll i = 1; i<=n; i++){
        dis[i] = LLONG_MAX;
        parent[i] = -1;
    }
    
    dijkstra(1);
    
    if(dis[n] == LLONG_MAX){
        cout << -1;
    }else{
        ll node = n;
        vector<ll> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for(auto ans : path)
            cout << ans << " ";
    }


    return 0;
}