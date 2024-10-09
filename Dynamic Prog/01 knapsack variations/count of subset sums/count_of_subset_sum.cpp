//gfg passed
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1


class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // code is exactly same as subset sum problem
        // tabulation
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        
        int mod = (int)1e9+7; 
        
        //initialisation
        for(int j =0; j < sum+1; j++) t[0][j] = 0;
        for(int i =0; i < n+1; i++) t[i][0] = 1;
        
        //choice diagram
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(arr[i-1]<= j){
                    // take + not take
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j])%mod;
                }
                else{
                    t[i][j] = (t[i-1][j])%mod;
                }
            }
        }
        return t[n][sum];
	}
	  
};
