class Solution {
public:
    int res = INT_MAX;

    void dfs(vector<int>& height, int n, int m, int cnt) {
        if (cnt >= res) return;

        int minH = INT_MAX, pos = -1;
        for (int i = 0; i < m; i++) {
            if (height[i] < minH) {
                minH = height[i];
                pos = i;
            }
        }

        if (minH == n) {
            res = min(res, cnt);
            return;
        }

        int end = pos;
        while (end < m && height[end] == minH) end++;

        int width = end - pos;

        for (int size = min(n - minH, width); size >= 1; size--) {
            for (int i = pos; i < pos + size; i++) {
                height[i] += size;
            }

            dfs(height, n, m, cnt + 1);

            for (int i = pos; i < pos + size; i++) {
                height[i] -= size;
            }
        }
    }

    int tilingRectangle(int n, int m) {
        if (n > m) swap(n, m);  // optimization
        vector<int> height(m, 0);
        dfs(height, n, m, 0);
        return res;
    }
};