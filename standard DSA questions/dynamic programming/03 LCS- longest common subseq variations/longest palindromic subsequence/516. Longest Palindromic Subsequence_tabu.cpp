// leetcode accepted
//516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int lcs(string a, string b){
        int m = a.size();
        int n = b.size();

        //table 
        int t[m+1][n+1];
        
        //initialisation
        for(int i = 0; i < m+1; i++) t[i][0] = 0;
        for(int i = 0; i < n+1; i++) t[0][i] = 0;

        //choice diagram
        for(int i =1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                //equal
                if(a[i-1] == b[j-1]) t[i][j] = 1+ t[i-1][j-1];
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m][n];
    }
    
    int longestPalindromeSubseq(string s) {
        // lps(s) = lcs(s, reverse(s))
        string rev = string(s.rbegin(), s.rend()); // using string cosntructor
        return lcs(s, rev);
    }
};
