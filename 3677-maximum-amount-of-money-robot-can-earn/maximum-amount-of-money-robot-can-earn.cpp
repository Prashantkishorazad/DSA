class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // dp[i][j][k]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        
        // Initialize start
        if (coins[0][0] >= 0) {
            for (int k = 0; k < 3; k++) {
                dp[0][0][k] = coins[0][0];
            }
        } else {
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = 0;
            dp[0][0][2] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                
                for (int k = 0; k < 3; k++) {
                    int val = coins[i][j];
                    int best = INT_MIN;
                    
                    // from top
                    if (i > 0) {
                        best = max(best, dp[i-1][j][k]);
                    }
                    
                    // from left
                    if (j > 0) {
                        best = max(best, dp[i][j-1][k]);
                    }
                    
                    // take value
                    if (best != INT_MIN) {
                        dp[i][j][k] = max(dp[i][j][k], best + val);
                    }
                    
                    // neutralize robber
                    if (val < 0 && k > 0) {
                        int best_prev = INT_MIN;
                        
                        if (i > 0) {
                            best_prev = max(best_prev, dp[i-1][j][k-1]);
                        }
                        if (j > 0) {
                            best_prev = max(best_prev, dp[i][j-1][k-1]);
                        }
                        
                        if (best_prev != INT_MIN) {
                            dp[i][j][k] = max(dp[i][j][k], best_prev);
                        }
                    }
                }
            }
        }
        
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};