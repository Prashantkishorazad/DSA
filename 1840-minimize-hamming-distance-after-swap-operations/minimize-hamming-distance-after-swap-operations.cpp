class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        // Step 1: Build DSU
        for (auto &p : allowedSwaps) {
            dsu.unite(p[0], p[1]);
        }

        // Step 2: Group indices
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[dsu.find(i)].push_back(i);
        }

        int result = 0;

        // Step 3: Process each group
        for (auto &g : groups) {
            unordered_map<int, int> freq;

            // count source values
            for (int idx : g.second) {
                freq[source[idx]]++;
            }

            // match with target
            for (int idx : g.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    result++;
                }
            }
        }

        return result;
    }
};