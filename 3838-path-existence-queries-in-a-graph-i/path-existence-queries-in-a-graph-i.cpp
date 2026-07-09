class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rankv[a] < rankv[b])
            swap(a, b);

        parent[b] = a;

        if (rankv[a] == rankv[b])
            rankv[a]++;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Connect adjacent nodes
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff)
                unite(i, i + 1);
        }

        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};