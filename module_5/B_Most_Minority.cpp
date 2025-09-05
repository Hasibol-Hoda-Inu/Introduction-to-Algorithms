#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;

    vector<string> p(n);

    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    vector<int> votes(n, 0);

    for(int j=0; j<m; j++){
        int ones = 0, zeros = 0;

        for(int i = 0; i<n; i++){
            if(p[i][j] == '1')
                ones++;
            else 
                zeros++;
        }

        if(ones == 0 || zeros == 0){
            for(int i=0; i<n; i++)
                votes[i]++;
        }else if(zeros<ones){
            for(int i=0; i<n; i++){
                if(p[i][j] == '0')
                    votes[i]++;
            }
        }else{
            for(int i=0; i<n; i++)
                if(p[i][j] == '1')
                    votes[i]++;
        }
        
    }


    int mx = 0;
    for(int i = 0; i<n; i++){
        if(votes[i] > mx)
            mx = votes[i];
    }

    bool first = true;
    for(int i= 0; i< n; i++){
        if(votes[i] == mx)
            cout << i+1 << " ";
    }
   
    return 0;
}