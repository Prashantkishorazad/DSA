class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n, 0);

        // forward pass
        for (int i = 0; i < n; i++) {
            if (i > 0) len[i] = len[i - 1];

            if (islower(s[i])) {
                len[i]++;
            } 
            else if (s[i] == '*') {
                len[i] = max(0LL, len[i] - 1);
            } 
            else if (s[i] == '#') {
                len[i] *= 2;
            }

            len[i] = min(len[i], (long long)1e15);
        }

        if (len[n - 1] <= k) return '.';

        // backward pass
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long currLen = len[i];
            long long prevLen = (i > 0 ? len[i - 1] : 0);

            if (islower(c)) {
                if (k == currLen - 1) return c;
            } 
            else if (c == '#') {
                if (k >= prevLen) k -= prevLen;
            } 
            else if (c == '%') {
                k = currLen - 1 - k;
            }
        }

        return '.';
    }
};