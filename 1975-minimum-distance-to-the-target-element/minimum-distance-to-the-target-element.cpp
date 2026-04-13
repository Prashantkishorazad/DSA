class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target && i == start) {
                return 0;
            }
        }
        
        int minDist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                minDist = min(minDist, abs(i - start));
            }
        }
        
        return minDist;
    }
};
