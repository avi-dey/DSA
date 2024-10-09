// lc accepted
// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    // recursive approach
    // time O(n3)
    // space O(n) - stack calls
    
    //helper
    int isPalin(string& s, int i, int j){
        if(i>=j) return 1;
        return s[i]== s[j] ? isPalin(s, i+1, j-1) : 0;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                count += isPalin(s, i, j);
            }
        }
        return count;
    }
};
