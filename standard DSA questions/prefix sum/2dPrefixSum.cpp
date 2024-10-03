#include <bits/stdc++.h>
using namespace std;

// 2D PREFIX SUM    
void solve(vector<vector<int>>& arr, int n){
    int ps[n][n]; // prefix sum matrix
    ps[0][0] = arr[0][0];

    //topmost row
    for(int i = 1; i <n; i++){
        ps[0][i] =  arr[0][i] + ps[0][i-1];
    }
    //leftmost col
    for(int i = 1; i < n; i++){
        ps[i][0] = arr[i][0] + ps[i-1][0];
    }
    
    // rest of the ps array
    for(int i = 1; i < n; i++){
        for(int j =1; j < n; j++){
            ps[i][j] = arr[i][j] + (ps[i-1][j] + ps[i][j-1]) - ps[i-1][j-1]; // subtracting the overlap
        }
    }


    //printing
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            cout << ps[i][j] << " ";
        }
        cout << endl;
    }

}
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n = 3; // size of 2 matrix
    vector<vector<int>> arr{
        {10, 20, 30},
        {5, 10, 20},
        {2, 4, 6}
    };

    solve(arr, n);
    return 0;
}