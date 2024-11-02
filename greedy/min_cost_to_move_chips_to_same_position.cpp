// lc passed
// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/?envType=problem-list-v2&envId=aoqzggwi&difficulty=EASY


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // we can reduce any given position array to array of size 2 
        // because +2 and -2 jumps are free
        // count(even) and count(odds)
        // essentially we have to decide where to make all evens jump or all odds jump, the lesser should jump to get the minimum cost

        int even = 0, odd = 0;
        for(int i = 0; i < position.size(); i++){
            if(position[i] & 1) even++;
            else odd++;
        }
        return min(odd, even);
    }
};