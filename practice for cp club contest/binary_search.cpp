#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i<n; i++)
        cin >> arr[i];
    
    int val; cin >> val;

    int l = 0;
    int r = n-1;
    bool flag = false;
    while (l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == val){
            flag = true;
            break;
        }else{
            if(val < arr[mid])
                r = mid-1;
            else
                l = mid+1;
        }
    }
    
        
    if(flag)
        cout << "Found";
    else
        cout << "Not Found";

    
    return 0;
}