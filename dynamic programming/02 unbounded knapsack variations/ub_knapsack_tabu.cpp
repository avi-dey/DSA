//GFG accepted
//https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // tabulation 
        int t[N+1][W+1];
        memset(t,0, sizeof(t));
        
        //initialisation
        for(int i = 0; i < N+1; i++) t[i][0] = 0;
        for(int i = 0; i < W+1; i++) t[0][i] = 0;
        
        for(int i = 1; i < N+1; i++){
            for(int j = 1; j < W+1; j++){
                //take - unprocessed
                // not take - processes
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],
                                t[i-1][j]);    
                }else{
                    t[i][j] = t[i-1][j]; // can't take
                }
                
            }
        }
        return t[N][W];
        
    }
};