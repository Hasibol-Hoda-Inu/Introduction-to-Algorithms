#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
int dp[100005][100005];
bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

int re(int i, int j){
    if()
        reutrn 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(valid(i, j))
        dp[i][j] = re(adj[i+1][j], adj[i][j+1]);
    return dp[i][j];
}

int main(){
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            adj[i].push_back(a);
        }
        
    }
    memset(dp, -1, sizeof(dp));
    
    re(0, 0);
    
    

    return 0;
}