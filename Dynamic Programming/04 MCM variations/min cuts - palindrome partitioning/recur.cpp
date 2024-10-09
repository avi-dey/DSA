//gfg tle
// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1


class Solution{
public:
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    int solve(string s, int i, int j){
        //base cases
        if(i>=j) return 0;
        if(isPalindrome(s, i, j) == true) return 0;
        
        int temp_ans;
        int mn = INT_MAX;
        for(int k =i; k <= j-1; k++){
            temp_ans = solve(s, i, k) + solve(s, k+1, j) + 1;
            if(temp_ans < mn){
                mn = temp_ans;
            }
        }
        return mn;
    }
    
    int palindromicPartition(string str)
    {
        int n = str.size();
        return solve(str, 0, n-1);
    }
};