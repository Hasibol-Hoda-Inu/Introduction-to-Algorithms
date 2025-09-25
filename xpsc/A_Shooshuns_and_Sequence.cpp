#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for(int i = 0; i<n; i++)
        cin >> v[i];
    
    for(int i = k; i<n; i++){
        if(v[i] != v[k-1]){
            cout << -1;
            return 0;
        }
    }
    
    int cnt = 0;
    for(int i = k-2; i>=0; i--){
        if(v[i] != v[k-1]){
            cnt = i+1;
            break;
        }
    }
    
    
    cout << cnt;


    return 0;
}