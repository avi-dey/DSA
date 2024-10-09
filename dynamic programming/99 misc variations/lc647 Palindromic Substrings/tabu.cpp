// lc accepted
// https://leetcode.com/problems/palindromic-substrings/
// didnot understand fully, can be better.
// why i starting from n and decrementing but j start i and incrementing

class Solution {
public:
    int countSubstrings(string s) {
        // tabulation
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int count = 0;

        for(int i= n; i>=0; i--){
            for(int j= i; j<n; j++){
                if(i == j){
                    dp[i][j] = 1; //initialisation(base case), single chars always true
                }
                else if( j == i+1){
                    //other base case(2 consecutive chars, check: if both are same then true else false)
                    dp[i][j] = s[i]==s[j] ? 1 : 0;
                }
                else{
                    //logic
                    dp[i][j] = s[i]==s[j] ? dp[i+1][j-1] : 0; //if same, check whether is i-1,j-1 is a palindrome or not
                }
                count += dp[i][j]; // every time we get a true(1) we add it to count
            }
        }
        return count;
    }
};
