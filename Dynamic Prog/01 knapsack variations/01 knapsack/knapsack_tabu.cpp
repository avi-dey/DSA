// coding ninja passed
// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?leftPanelTabValue=SUBMISSION

// n is size of weight and vector array i.e. the no. of items 
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> t(n+1, vector<int>(maxWeight+1 , -1));
    
    // base case
    for(int i = 0; i< n+1; i++){
        for(int j = 0; j< maxWeight+1; j++){
            if(i ==0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    //choice diagram
    for(int i = 1; i< n+1; i++){
        for(int j = 1; j< maxWeight+1; j++){
            if(weight[i-1]<=j){
                t[i][j] = max(value[i-1]+t[i-1][j-weight[i-1]],
                t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][maxWeight];
}
