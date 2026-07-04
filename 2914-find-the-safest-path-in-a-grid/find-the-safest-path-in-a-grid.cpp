#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Phase 1: Multi-Source BFS
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Push all thieves into the queue to start the BFS
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // Calculate shortest Manhattan distance to any thief for every cell
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Phase 2: Max-Heap Dijkstra Pathfinding
        // Store: {minimum_safeness_on_path, {row, col}}
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({dist[0][0], {0, 0}});
        visited[0][0] = true;
        
        while (!pq.empty()) {
            auto [safe, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();
            
            // Goal reached. Because of the Max-Heap, this is guaranteed to be optimal.
            if (r == n - 1 && c == n - 1) {
                return safe;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The path's safeness is the bottleneck (minimum) of the current path safeness and the next cell
                    int min_safe = min(safe, dist[nr][nc]);
                    pq.push({min_safe, {nr, nc}});
                }
            }
        }
        
        return 0;
    }
};