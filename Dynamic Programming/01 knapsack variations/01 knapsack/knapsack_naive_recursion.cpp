/* A Naive recursive implementation of 
 0-1 Knapsack problem */
#include <iostream> 
using namespace std; 

/* W: total weight of the bag/knapsack
wt: weights
val: values/profit/cost
n: size of the array weight/value
*/

// A utility function that returns 
// maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int W, int wt[], int val[], int n){
    // base case
    if (n == 0 || W == 0)
        return 0;

    // choice diagram
    if (wt[n-1] <= W){
        return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
        knapSack(W, wt, val, n-1));
    }
    else
        return knapSack(W, wt, val, n-1);

}


// Driver code 
int main() 
{ 
    int profit[] = { 60, 100, 120 }; 
    int weight[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    cout << knapSack(W, weight, profit, n); 
    return 0; 
} 