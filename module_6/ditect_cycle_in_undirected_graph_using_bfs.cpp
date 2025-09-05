#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];
int parent[101];
bool visited[101];
bool cycle;

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        // cout << p << endl;

        for(int child : adj_list[p]){
            if(visited[child] && parent[p] != child)
                cycle = true;
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                parent[child] = p;
            }
        }
    }
    
}

int main(){
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cycle = false;

    for(int i = 0; i<n; i++)
        if(!visited[i])
            bfs(i);
    
    if(cycle)
        cout << "has cycle";
    else 
        cout << "hasn't";

    return 0;
}