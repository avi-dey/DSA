// accepted
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // knapsack variation
        // sum = bag - condition 1 satisfy
        // options to choice elements - condition 2 satisfy
        int n = arr.size();
        vector<vector<int>> t (n+1, vector<int>(sum+1, -1));
        // base case
        // first row= arr empty and sum 1 2 3 4..... => not possible (excpet 0,0 cell)=> first row all false
        // first col= all true since we need to achieve sum=0 and that is achievable by any array of any size
        for(int j = 0; j < sum+1; j++) t[0][j]= false;
        for(int i = 0; i < n+1; i++) t[i][0]= true;
        
        //choice diagram
        for(int i = 1; i < n+1; i++){
            for(int j =1; j < sum+1; j++){
                if(arr[i-1]<= j){ //two options= take or not take
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
        
    }
};
