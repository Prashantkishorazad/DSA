#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = nums.size();

        vector<long long> mult(n, 1);

        // Process queries
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int i = l; i <= r; i += k) {
                mult[i] = (mult[i] * v) % MOD;
            }
        }

        // Final XOR
        int result = 0;
        for (int i = 0; i < n; i++) {
            long long val = (nums[i] * mult[i]) % MOD;
            result ^= val;
        }

        return result;
    }
};