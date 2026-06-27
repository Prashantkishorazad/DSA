class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        // Special case for 1
        if (cnt.count(1)) {
            ans = max(ans, (cnt[1] % 2 == 0) ? cnt[1] - 1 : cnt[1]);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 1;

            while (cnt[cur] >= 2) {
                long long nxt = cur * cur;
                if (!cnt.count(nxt)) break;
                len += 2;
                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};