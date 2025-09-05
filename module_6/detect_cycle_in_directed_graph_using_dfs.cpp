#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[101];
bool visited[101];
bool path[101];
bool cycle;

void dfs(int src){
    visited[src] = true;
    path[src] = true;
    for(int child : adj_list[src]){
        if(visited[child] && path[child])
            cycle = true;
        if(!visited[child]){
           
            dfs(child);
        }
    }
    path[src] = false;
}

int main(){
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);     
    }
    
    memset(visited, false, sizeof(visited));
    memset(path, false, sizeof(path));
    cycle = false;

    for(int i = 0; i<n; i++)
        if(!visited[i])
            dfs(i);
    

    if(cycle)
        cout << "cycle detected";
    else 
        cout << "has no cycle";

    
    return 0;
}