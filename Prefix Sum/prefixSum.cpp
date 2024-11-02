#include <bits/stdc++.h>
using namespace std;

// 1D PREFIX SUM   
void solve(int arr[], int n){
    int ps[n]; // prefix sum array
    ps[0] = arr[0];
    for(int i = 1; i< n; i++){
        ps[i] = arr[i] + ps[i-1];
    }


    // printing 
    for(int a: ps){
        cout << a << ", ";
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

	//input order: no. of tc, size of array of the respective tc, elements of the respective array
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        int arr[n]; //1d array
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }        

        solve(arr, n);
    }
    return 0;
}
