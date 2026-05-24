class Solution {
public:
    int n;
    vector<int> memo;

    int dfs(vector<int>& arr, int i, int d) {
        if (memo[i] != -1) return memo[i];

        int best = 1; // at least visit index i itself

        // Jump right
        for (int x = 1; x <= d && i + x < n; x++) {
            if (arr[i + x] >= arr[i]) break; // barrier
            best = max(best, 1 + dfs(arr, i + x, d));
        }

        // Jump left
        for (int x = 1; x <= d && i - x >= 0; x++) {
            if (arr[i - x] >= arr[i]) break; // barrier
            best = max(best, 1 + dfs(arr, i - x, d));
        }

        return memo[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memo.assign(n, -1);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(arr, i, d));

        return ans;
    }
};