class Solution {
    public int[] gcdValues(int[] nums, long[] queries) {
        int mx = 0;
        for (int x : nums) mx = Math.max(mx, x);

        int[] freq = new int[mx + 1];
        for (int x : nums) freq[x]++;

        long[] cnt = new long[mx + 1];

        // Count numbers divisible by each divisor
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d) {
                cnt[d] += freq[j];
            }
        }

        // exact[d] = number of pairs whose gcd is exactly d
        long[] exact = new long[mx + 1];
        for (int d = mx; d >= 1; d--) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;
            for (int j = d + d; j <= mx; j += d) {
                exact[d] -= exact[j];
            }
        }

        // Prefix sums
        long[] prefix = new long[mx + 1];
        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        int[] ans = new int[queries.length];

        // Binary search for each query
        for (int i = 0; i < queries.length; i++) {
            long target = queries[i] + 1;

            int l = 1, r = mx;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (prefix[mid] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans[i] = l;
        }

        return ans;
    }
}