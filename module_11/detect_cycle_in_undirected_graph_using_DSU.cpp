#include<bits/stdc++.h>
using namespace std;

int parent[101];
int group_size[101];

int find(int node){
    if(parent[node] == -1)
        return node;
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int a, int b){
    int leader1 = find(a);
    int leader2 = find(b);
    // cout << "union leader1-> " << leader1 << " union leader2-> " << leader2 << endl;
    if(group_size[leader1] >= group_size[leader2]){
        parent[leader2] = leader1;
        group_size[leader1]+=group_size[leader2];
    }else{
        parent[leader1] = leader2;
        group_size[leader2]+= group_size[leader1];
    }

}

int main(){
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    memset(parent, -1, sizeof(parent));
    memset(group_size, 1, sizeof(group_size));

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        
        int leaderA = find(a);
        int leaderB = find(b);
        // cout << "leaderA-> " << leaderA << " leaderB-> " << leaderB << endl;
        if(leaderA == leaderB)
            cycle = true;
        else
            dsu_union(a,b);
    }
    
    if(cycle)
        cout << "Cycle detected";
    else
        cout << "No cycle";

    return 0;
}