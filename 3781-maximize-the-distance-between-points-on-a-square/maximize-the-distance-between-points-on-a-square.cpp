#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getPos(long long x, long long y, long long side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3 * side - x;
        return 4 * side - y;
    }

    bool can(vector<long long>& a, int k, long long d, long long per) {
        int n = a.size();
        vector<long long> b = a;
        for (auto x : a) b.push_back(x + per);

        int m = b.size();
        vector<int> nxt(m);

        // two pointer to find next valid index
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j < m && b[j] - b[i] < d) j++;
            nxt[i] = j;
        }

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            int cur = i;

            while (cnt < k) {
                if (nxt[cur] >= i + n) break;
                cur = nxt[cur];
                cnt++;
            }

            if (cnt == k) {
                if (per - (b[cur] - b[i]) >= d)
                    return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> pos;

        for (auto &p : points) {
            pos.push_back(getPos(p[0], p[1], side));
        }

        sort(pos.begin(), pos.end());

        long long per = 4LL * side;
        long long low = 0, high = 2 * side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (can(pos, k, mid, per)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};