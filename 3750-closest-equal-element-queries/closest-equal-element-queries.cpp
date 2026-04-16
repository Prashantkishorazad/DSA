#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            auto &vec = mp[nums[q]];
            
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            auto it = lower_bound(vec.begin(), vec.end(), q);
            int res = INT_MAX;
            
            int idx = it - vec.begin();
            
            // Check next index (circular)
            int next = vec[(idx + 1) % vec.size()];
            int dist1 = abs(next - q);
            res = min(res, min(dist1, n - dist1));
            
            // Check previous index (circular)
            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int dist2 = abs(prev - q);
            res = min(res, min(dist2, n - dist2));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};