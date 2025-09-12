#include<bits/stdc++.h>
using namespace std;

int group_size[100005];
int parent[100005];
int cmp, mx;

int find(int node){
    if(parent[node] == -1)
        return node;
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int a, int b){
    int leaderA = find(a);
    int leaderB = find(b);
    if(leaderA == leaderB)
        return;
    if(parent[leaderA] >= parent[leaderB]){
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
        mx = max(mx, group_size[leaderA]);
    }else{
        parent[leaderA] = leaderB;
        group_size[leaderB]+= group_size[leaderA];
        mx = max(mx, group_size[leaderB]);
    }
    cmp--;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i<=n; i++){
        parent[i] = -1;
        group_size[i] = 1;
    }

    cmp = n;
    mx = 1;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }
    
    

    return 0;
}