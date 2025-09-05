#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n; 
    // vector<long long > v(n);
    priority_queue<long long> pq;
    long long sum = 0;

    for(int i=  0; i<n; i++){
        long long g;
        cin >> g;
        pq.push(g);
        
        // cin >> v[i];
        // sum+= v[i];
    }
    

    while (pq.size() > 1)
    {
        long long g_a = pq.top();
        pq.pop();
        long long g_b = pq.top();
        pq.pop();

        sum+= g_a;

        if(g_a - g_b > 0)
            pq.push(g_a - g_b);
    }
    



    // for(int i = 0, j = 1; j<n; i++, j++){
    //     sum+= max(v[i], v[j]);
    // }


    // sort(v.rbegin(), v.rend());
    // long long ans = sum - v[0];

    cout << sum << endl;

    return 0;
}