// tle
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{   
public:
    bool solve(vector<int> arr, int n, int sum){
        // base cases
        // sum = 0 is achievable with array of any size --> empty array
        // n = 0 and sum = 1,2,3,.... is not achievable
        if(sum == 0) return true;
        if(n== 0) return false;
        
        if(arr[n-1] <= sum){
            return solve(arr, n-1, sum-arr[n-1]) || solve(arr, n-1, sum);
        }else{
            return solve(arr, n-1, sum);
        }
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> t (n+1, vector<int>(sum+1, -1));
        bool res = solve(arr, n, sum);
        return res;
    }
};