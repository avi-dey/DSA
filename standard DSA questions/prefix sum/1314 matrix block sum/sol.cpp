// lc passed
// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // 2d prefix sum
        vector<vector<int>> psum (m+1, vector<int>(n+1, 0));
        for(int i = 1; i< m+1; i++){
       
            for(int j = 1; j< n+1; j++){
                psum[i][j] = (psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]) + mat[i-1][j-1]; // subtacting the overlap
            }
        }

        //now the ans
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i= 0; i< m; i++){
            for(int j = 0; j <n; j++){
                // calculate the index range 
                //     c1
                // r1      r2
                //     c2
                int r1 = max(0, i-k); int r2 = min(m-1, i+k);
                int c1 = max(0, j-k); int c2 = min(n-1, j+k);
                //increment 1 on each to match the 2d psum vector
                r1++; r2++; c1++; c2++;

                ans[i][j] = psum[r2][c2] // right-bottom
                            -  (psum[r2][c1-1] + psum[r1-1][c2] - psum[r1-1][c1-1]);
            }
        }
        return ans;
    }
};
