class Solution {
    static final int MOD = 1_000_000_007;

    public int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;

        long[] dpUp = new long[k];
        long[] dpDown = new long[k];

        // base case
        for (int i = 0; i < k; i++) {
            dpUp[i] = 1;
            dpDown[i] = 1;
        }

        long[] newUp = new long[k];
        long[] newDown = new long[k];
        long[] prefixUp = new long[k + 1];
        long[] prefixDown = new long[k + 1];

        for (int len = 2; len <= n; len++) {

            // build prefix sums
            prefixUp[0] = 0;
            prefixDown[0] = 0;

            for (int j = 0; j < k; j++) {
                prefixUp[j + 1] = (prefixUp[j] + dpUp[j]) % MOD;
                prefixDown[j + 1] = (prefixDown[j] + dpDown[j]) % MOD;
            }

            for (int j = 0; j < k; j++) {

                // UP → DOWN (x > j)
                newDown[j] = (prefixUp[k] - prefixUp[j + 1] + MOD) % MOD;

                // DOWN → UP (x < j)
                newUp[j] = prefixDown[j];
            }

            // swap arrays instead of re-allocating
            long[] temp = dpUp;
            dpUp = newUp;
            newUp = temp;

            temp = dpDown;
            dpDown = newDown;
            newDown = temp;
        }

        long ans = 0;
        for (int j = 0; j < k; j++) {
            ans = (ans + dpUp[j] + dpDown[j]) % MOD;
        }

        return (int) ans;
    }
}