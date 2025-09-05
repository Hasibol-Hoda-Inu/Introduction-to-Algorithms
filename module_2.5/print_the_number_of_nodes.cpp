#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[10];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int idx; cin >> idx;
    
    cout << adj_list[idx].size();
    
    return 0;
}