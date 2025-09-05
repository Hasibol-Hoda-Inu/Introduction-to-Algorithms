#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
bool visited[200005];

void dfs(int src){
    visited[src] = true;
    for(int child : adj[src])
        if(!visited[child])
            dfs(child);
}

int main(){
    int n, m;
    cin >> n >> m;
   
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    vector<int> v;

    for (int i = 1; i<=n; i++)
    {   
        if(!visited[i]){
            v.push_back(i);
            dfs(i);
        }
    }
    
    cout << v.size()-1 << endl;
    if(v.size()-1 == 0)
        return 0;

    for(int i = 0, j = 1; j<v.size(); i++, j++)
        cout << v[i] << " " << v[j] << endl;
    

    return 0;
}