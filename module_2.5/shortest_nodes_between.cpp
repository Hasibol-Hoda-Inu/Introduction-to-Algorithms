#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[101];

void bfs(int src, bool visited[], int level[]){
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
            }
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    
    while(e--){
        int a, b;
        cin >>a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }


    int q; cin >> q;
    while(q--){
        int s, d;
        cin >> s >> d;

        bool visited [n+1];
        int level [n+1];
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));

        bfs(s, visited, level);

        if(level[d] != -1){
            cout << level[d] << endl;
        }else
            cout << -1 << endl;

    }
    

    
    return 0;
}