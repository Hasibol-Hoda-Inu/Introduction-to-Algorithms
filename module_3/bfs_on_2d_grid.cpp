#include<bits/stdc++.h>
using namespace std;

int r, c;
char grid[101][101];
bool visited[101][101];
vector<pair<int,int>> d = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool is_valid(int i, int j){
    if(i<0 || i>=r || j<0 || j>=c)
        return false;
    return true;
}

void bfs(int si, int sj){
   queue<pair<int, int>> q;
   q.push({si, sj});
   visited[si][sj] = true;

   while(!q.empty()){
    pair<int, int> p = q.front();
    q.pop();

    int p_i = p.first;
    int p_j = p.second;

    ///TODO: kaj korbo
    cout << p_i << " " << p_j << endl;


    for(int i=0; i<4; i++){
        int ci = p_i + d[i].first;
        int cj = p_j + d[i].second;

        if(is_valid(ci, cj) && !visited[ci][cj]){
            q.push({ci, cj});
            visited[ci][cj] = true;

        }
    }
   }
}

int main(){
    
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
        
    }

    int si, sj;
    cin >> si >> sj;
    memset(visited, false, sizeof(visited));
    bfs(si, sj);


    return 0;
}