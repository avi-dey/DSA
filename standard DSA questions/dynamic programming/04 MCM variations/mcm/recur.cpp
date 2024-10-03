// gfg tle
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


class Solution{
public:
    int solve(int arr[], int i, int j){
        //base case
        if(i == j) return 0;
        
        int mn = INT_MAX;
        int temp_ans;
        
        for(int k = i; k <= j-1; k++){
            temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            
            if(temp_ans < mn){
                mn = temp_ans;
            }
        }
        return mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        int i = 1;
        int j = N-1;
        return solve(arr, i , j);
    }
};
