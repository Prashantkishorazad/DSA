#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // Directions: North, East, South, West
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int d = 0; // start facing North
        
        int x = 0, y = 0;
        int maxDist = 0;
        
        // Store obstacles in set
        set<pair<int,int>> obstacleSet;
        for (auto &obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }
        
        for (int cmd : commands) {
            if (cmd == -1) {
                // turn right
                d = (d + 1) % 4;
            } 
            else if (cmd == -2) {
                // turn left
                d = (d + 3) % 4;
            } 
            else {
                // move forward step by step
                int dx = dirs[d].first;
                int dy = dirs[d].second;
                
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    // stop if obstacle
                    if (obstacleSet.count({nx, ny})) {
                        break;
                    }
                    
                    x = nx;
                    y = ny;
                    
                    // update max distance
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};