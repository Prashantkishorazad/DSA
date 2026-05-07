class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> change(n, 0);

        for (int i = 0; i < n; i++) {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;

            change[low] += 1;
            change[high] -= 1;

            if (low >= high) {
                change[0] += 1;
            }
        }

        int maxScore = -1, score = 0, bestK = 0;

        for (int k = 0; k < n; k++) {
            score += change[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }

        return bestK;
    }
};