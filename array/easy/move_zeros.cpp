// https://leetcode.com/problems/move-zeroes/submissions/1373216348/
// lc passed

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //self swap is possible for first non zero elements
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};


//my dumb soln

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }
        while(i<n){
            nums[i++] = 0;
        }
    }
};
