class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    string s1, s2, evil;
    vector<int> lps;
    int dp[501][51][2][2];

    // Build LPS (KMP)
    void buildLPS() {
        int m = evil.size();
        lps.assign(m, 0);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && evil[i] != evil[j])
                j = lps[j - 1];
            if (evil[i] == evil[j]) j++;
            lps[i] = j;
        }
    }

    int dfs(int i, int j, bool tightLow, bool tightHigh) {
        if (j == evil.size()) return 0; // evil found ❌
        if (i == n) return 1;

        int &res = dp[i][j][tightLow][tightHigh];
        if (res != -1) return res;

        res = 0;

        char low = tightLow ? s1[i] : 'a';
        char high = tightHigh ? s2[i] : 'z';

        for (char c = low; c <= high; c++) {
            int nj = j;

            // KMP transition
            while (nj > 0 && c != evil[nj])
                nj = lps[nj - 1];
            if (c == evil[nj]) nj++;

            res = (res + dfs(
                i + 1,
                nj,
                tightLow && (c == low),
                tightHigh && (c == high)
            )) % MOD;
        }

        return res;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->n = n;
        this->s1 = s1;
        this->s2 = s2;
        this->evil = evil;

        memset(dp, -1, sizeof(dp));
        buildLPS();

        return dfs(0, 0, true, true);
    }
};