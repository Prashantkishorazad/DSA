#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // directions: {dx, dy}
        vector<vector<vector<int>>> dir = {
            {},
            {{0,-1},{0,1}},   // type 1
            {{-1,0},{1,0}},   // type 2
            {{0,-1},{1,0}},   // type 3
            {{0,1},{1,0}},    // type 4
            {{0,-1},{-1,0}},  // type 5
            {{0,1},{-1,0}}    // type 6
        };

        // check if next cell connects back
        auto isValid = [&](int x, int y, int px, int py) {
            for (auto &d : dir[grid[x][y]]) {
                if (x + d[0] == px && y + d[1] == py)
                    return true;
            }
            return false;
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m-1 && y == n-1) return true;

            for (auto &d : dir[grid[x][y]]) {
                int nx = x + d[0], ny = y + d[1];

                if (nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny]) {
                    if (isValid(nx, ny, x, y)) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }
};