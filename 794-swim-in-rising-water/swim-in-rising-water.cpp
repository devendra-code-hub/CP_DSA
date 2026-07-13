class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(); 
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
         
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
         
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            int current_max = current.first;
            int r = current.second.first;
            int c = current.second.second;
           
            if (r == n - 1 && c == n - 1) {
                return current_max;
            } 
            for (int i = 0; i < 4; i++) {
                int nr = r + delr[i];
                int nc = c + delc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true; 
                    int next_max = max(current_max, grid[nr][nc]);
                    pq.push({next_max, {nr, nc}});
                }
            }
        }
        
        return 0;
    }
};