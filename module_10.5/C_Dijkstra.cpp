#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100005];
long long dis[100005];
int parents[100005];

void dijkstra(int src){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> >pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int pn = p.second;
        long long pd = p.first;
       
        
        for(auto child : adj[pn]){
            int child_node = child.first;
            long long child_dis = child.second;
   
            if(pd + child_dis < dis[child_node]){
                dis[child_node] = pd + child_dis;
                pq.push({dis[child_node], child_node});
                parents[child_node] = pn;
            }
        }
    }
}

int main(){
    int n, m; 
    cin >> n >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i = 1; i<=n; i++)
        dis[i] = LLONG_MAX;

    memset(parents, -1, sizeof(parents));
    dijkstra(1);
    if(dis[n] == LLONG_MAX){
        cout << -1;
        return 0;
    }

    vector<int> v;
    int x = n;

    while (x != -1)
    {
        v.push_back(x);
        x = parents[x];
    }
    
    reverse(v.begin(), v.end());
    
    for(int val : v)
        cout << val << " ";

    
    return 0;
}