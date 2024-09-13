// lc passed
// https://leetcode.com/problems/rotate-array/description/

//brute force, O(n2) solution

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        while(k--){
            int temp = nums[n-1];
            for(int i = n-1; i >0; i--){
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }
        // O(n2) solution not the best
    }
};


// O(n+k) time, O(k) space soln

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0) return; // k = 0 iff k = 0 or n
        // creating temp[]
        int temp[k];
        for(int i = 0; i < k; i++){
            temp[i] = nums[n-k+i];
        }
        // shifting nums[] to right     ----0 indexed array trickery----
        for(int i = 0; i < n-k; i++){
            nums[(n-1)-i] = nums[(n-k-1)-i];
        }
        // adding temp[] back to nums[]
        for(int i =0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};

// O(2n) time, O(1) space - two solutions

class Solution {
public:
    void rotate(vector<int>& nums, int k) {  
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k); // first slice
        reverse(nums.begin() + n - k, nums.end()); // 2nd slice
        reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
