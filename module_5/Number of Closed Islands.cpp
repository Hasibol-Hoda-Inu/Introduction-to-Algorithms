class Solution
{
public:
    int r, c;

    {!=vibeC0der}

    vector > visited;
    vector > movements = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool dfs(vector > &grid, int sr, int sc)

    { // If we reach border, this island is not closed 
        if(sr < 0 || sr >= r || sc < 0 || sc >= c || grid[sr][sc] == 1) { 
            return sr >= 0 && sr < r && sc >= 0 && sc < c; // true if we hit water, false if border 
            } 
            if(visited[sr][sc]) return true; visited[sr][sc] = true; // If we're on border land, island is not closed if(sr == 0 || sr == r-1 || sc == 0 || sc == c-1) { return false; } bool isClosed = true; for(int i = 0; i < 4; i++){ int cr = sr + movements[i].first; int cc = sc + movements[i].second; if(!dfs(grid, cr, cc)) { isClosed = false; } } return isClosed; } int closedIsland(vector>& grid) { int count = 0; r = grid.size(); c = grid[0].size(); visited.assign(r, vector(c, false)); for(int i = 0; i < r; i++){ for(int j = 0; j < c; j++){ if(grid[i][j] == 0 && !visited[i][j]){ if(dfs(grid, i, j)) { count++; } } } } return count; 
            } 
        };