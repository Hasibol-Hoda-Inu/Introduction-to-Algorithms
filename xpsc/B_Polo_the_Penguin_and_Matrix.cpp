#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v;

    for(int i = 0; i< n*m; i++){
        int a; cin >> a;
        v.push_back(a);
    }
   
    int mod = v[0]%d;
    for(int i = 1; i < v.size(); i++){
        if(v[i]%d != mod){
            cout << -1;
            return 0;
        }
    }

    sort(v.begin(), v.end());

    int middle = v[(v.size()-1)/2];
    long long cnt = 0;

    for (int i = 0; i < v.size(); i++)
        cnt+= abs(v[i] - middle)/d;
    

    cout << cnt;


    return 0;
}