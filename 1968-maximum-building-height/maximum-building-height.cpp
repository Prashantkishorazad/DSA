class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Step 1: add mandatory restrictions
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        // Step 2: sort
        sort(restrictions.begin(), restrictions.end());

        // Step 3: left to right
        for (int i = 1; i < restrictions.size(); i++) {
            int dist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i-1][1] + dist);
        }

        // Step 4: right to left
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            int dist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1],
                                     restrictions[i+1][1] + dist);
        }

        // Step 5: compute answer
        int ans = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            int x1 = restrictions[i-1][0], h1 = restrictions[i-1][1];
            int x2 = restrictions[i][0], h2 = restrictions[i][1];

            int d = x2 - x1;
            int peak = (h1 + h2 + d) / 2;

            ans = max(ans, peak);
        }

        return ans;
    }
};