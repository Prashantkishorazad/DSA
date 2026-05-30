class Solution {
public:
    vector<int> tree;
    int N;

    void update(int idx, int val) {
        idx += N;
        tree[idx] = val;
        for (idx >>= 1; idx >= 1; idx >>= 1)
            tree[idx] = max(tree[2*idx], tree[2*idx+1]);
    }

    int query(int l, int r) {
        int res = 0;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxX = 0;
        for (auto& q : queries)
            maxX = max(maxX, q[1]);

        // Iterative segment tree
        N = maxX + 1;
        tree.assign(2 * N, 0);

        // Sorted obstacles with sentinels
        set<int> obs;
        obs.insert(0);
        obs.insert(maxX + 1); // right sentinel

        // Initially: gap from 0 to maxX+1
        // store at position maxX+1: gap = maxX+1
        // but we only query [0, x] so sentinel won't interfere

        vector<bool> result;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int p = q[1];

                auto it = obs.upper_bound(p);
                int nxt = *it;
                --it;
                int prv = *it;

                // p splits gap [prv, nxt] into [prv,p] and [p,nxt]
                // Store gap at RIGHT endpoint of each gap
                update(p, p - prv);
                if (nxt <= maxX)
                    update(nxt, nxt - p);

                obs.insert(p);

            } else {
                int x = q[1], sz = q[2];

                // Max gap with right endpoint in [0, x]
                int maxGap = query(0, x);

                // Trailing gap: from last obstacle <= x to x
                auto it = obs.upper_bound(x);
                --it;
                int lastObs = *it;
                maxGap = max(maxGap, x - lastObs);

                result.push_back(maxGap >= sz);
            }
        }

        return result;
    }
};