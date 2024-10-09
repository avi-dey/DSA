// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// gfg accepted


class Solution{
public:
    int t[100][100]; //constraints 
    
    int solve(int arr[], int i, int j){
        //base case
        if(i == j) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int mn = INT_MAX;
        int temp_ans;
        
        for(int k = i; k <= j-1; k++){
            temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            
            if(temp_ans < mn){
                mn = temp_ans;
            }
        }
        return t[i][j] = mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N-1;
        
        memset(t, -1, sizeof(t));
        
        return solve(arr, i , j);
    }
};
