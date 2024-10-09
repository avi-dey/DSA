// leetcode accepted 
// https://leetcode.com/problems/shortest-common-supersequence/
// 1092. Shortest Common Supersequence


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //solving lcs
        int m = str1.size();
        int n = str2.size();

        //table 
        int t[m+1][n+1];

        //initialisation
        for(int i = 0; i < n+1; i++) t[0][i] = 0;
        for(int i = 0; i < m+1; i++) t[i][0] = 0;

        //choice diag
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                //equal
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{ //not equal
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }    
        }
        //table is ready

        string ans = "";
        int i = m;
        int j = n;
        while(i>0 && j>0){
            //equal
            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }else{ //not equal
                if(t[i-1][j] > t[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }

        reverse(ans.begin(), ans.end()); // reverse the string
        return ans;
    }
};
