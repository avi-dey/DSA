// lc accepted
// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    // memoize approach

    // time O(n2)
    // space O(n2)
    
    //helper
    int isPalin(string& s, int i, int j, vector<vector<int>>& t){
        if(i>=j) return 1;
        if(t[i][j] != -1) return t[i][j];
        return t[i][j] = (s[i]== s[j] ? isPalin(s, i+1, j-1, t) : 0);
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> t (n+1, vector<int>(n+1, -1));

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                count += isPalin(s, i, j, t);
            }
        }
        return count;
    }
};
