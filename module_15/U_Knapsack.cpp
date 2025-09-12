#include<bits/stdc++.h>
using namespace std;

int arv[1005], arw[55];

int knapsack(int i, int w){
    if(i<0 || w <= 0)
        return 0;
    if(arw[i] <= w){
        int opt1 = knapsack(i-1, w - arw[i]) + arv[i];
        int opt2 = knapsack(i-1, w);
        return max(opt1, opt2);
    }else
        return knapsack(i-1, w);

}

int main(){
    int n, w; cin >> n >> w;

    for(int i = 0; i<n; i++)
        cin >> arw[i] >> arv[i];
    
    cout << knapsack(n-1, w);
    
    return 0;
}