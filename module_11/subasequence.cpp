#include <bits/stdc++.h>
using namespace std;

int main() {
	
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> v(n);
        
        for(int i =0; i<n; i++)
            cin >> v[i];
            
         
        int cnt1 =0, cnt2=0;
        
        int flag = 0;
        
        for(int i=0; i<n; i++)
            if(v[i] % 2 == flag){
                cnt1++;
                flag = !flag;
            }
            
        flag =1;
        
        for(int i=0; i<n; i++)
            if(v[i] % 2 == flag){
                cnt2++;
                flag = !flag;
            }
            
        cout << max(cnt1, cnt2) << endl;    
    }
    
    return 0;
}