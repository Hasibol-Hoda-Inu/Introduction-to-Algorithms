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

void dfs(int si, int sj){
    cout << si << " " << sj << endl;
    visited[si][sj] = true;
    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        // cout << ci << " " << cj << endl;
        if(is_valid(ci, cj) && !visited[ci][cj]){
            dfs(ci, cj);
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
    dfs(si, sj);


    return 0;
}