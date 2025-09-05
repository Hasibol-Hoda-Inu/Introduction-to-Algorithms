#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100001];
bool visited[100001];
int level[100001];
int parent[100001];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();



        for(int child : adj_list[p]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[p]+1;
                parent[child] = p;
            }
        }
    }
    
}

int main(){
    int n, m;
    cin >> n >> m;
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(1);

    int node = n;
    // vector<int> path; 
    stack<int> path;                // using stack here is more optimized solution. 

    while(node != -1){ 
        // path.push_back(node);
        path.push(node);
        node = parent[node];
    }

    // reverse(path.begin(), path.end());

    if(visited[n]){
        cout << level[n]+1 << endl;
        // for(int p : path)
        //     cout << p << " ";
        while(!path.empty()){
            cout << path.top() << " ";
            path.pop();
        }
    }else
        cout << "IMPOSSIBLE";
    

    
    return 0;
}