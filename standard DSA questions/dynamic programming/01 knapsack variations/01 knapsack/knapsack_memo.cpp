// coding ninja passed 
// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value, int n, int maxWeight,
             vector<vector<int>> &dp) {
    //base case
    if (n==0 || maxWeight ==0)
        return 0;

    //dp
    if (dp[n][maxWeight] != -1){
        return dp[n][maxWeight];
    }

    //choice diagram
    if(weight[n-1]<=maxWeight){
        //two choice, take the optimal
        dp[n][maxWeight] = max(value[n-1] + solve(weight,value, n-1 ,maxWeight-weight[n-1], dp),
        solve(weight,value, n-1, maxWeight,dp));
    }
    else{
        dp[n][maxWeight] = solve(weight,value, n-1, maxWeight, dp);
    }

    return dp[n][maxWeight];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
    int res = solve(weight, value, n, maxWeight, dp);
    return res;
}
