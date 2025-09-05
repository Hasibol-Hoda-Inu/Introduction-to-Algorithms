#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[10];
bool visited [10];
int level [10];
vector<int> v;

void bfs(int src, int l){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        if(level[p] == l)
            v.push_back(p);

        for(int child : adj_list[p]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                level[child] = level[p]+1;
            }
        }
    }
    
}

int main(){
    int n, e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    int l; cin >> l;
    bfs(0, l);

    sort(v.begin(), v.end(), greater<int>());

    for(int x : v)
        cout << x << " ";
    

    return 0;
}