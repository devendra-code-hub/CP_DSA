#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int num_layers = min(m, n) / 2;
        
        for (int layer = 0; layer < num_layers; ++layer) {
            // 1. Define boundaries for the current layer
            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;
            
            vector<int> flat_layer;
            
            // 2. Extract elements in counter-clockwise order
            // Top edge (Left to Right)
            for (int i = left; i <= right; ++i) flat_layer.push_back(grid[top][i]);
            // Right edge (Top to Bottom)
            for (int i = top + 1; i <= bottom; ++i) flat_layer.push_back(grid[i][right]);
            // Bottom edge (Right to Left)
            for (int i = right - 1; i >= left; --i) flat_layer.push_back(grid[bottom][i]);
            // Left edge (Bottom to Top)
            for (int i = bottom - 1; i > top; --i) flat_layer.push_back(grid[i][left]);
            
            // 3. Calculate effective rotations
            int L = flat_layer.size();
            int shift = k % L;
            
            // Create a shifted version of the layer
            vector<int> rotated_layer(L);
            for (int i = 0; i < L; ++i) {
                rotated_layer[i] = flat_layer[(i + shift) % L];
            }
            
            // 4. Put the rotated elements back into the grid
            int idx = 0;
            // Top edge
            for (int i = left; i <= right; ++i) grid[top][i] = rotated_layer[idx++];
            // Right edge
            for (int i = top + 1; i <= bottom; ++i) grid[i][right] = rotated_layer[idx++];
            // Bottom edge
            for (int i = right - 1; i >= left; --i) grid[bottom][i] = rotated_layer[idx++];
            // Left edge
            for (int i = bottom - 1; i > top; --i) grid[i][left] = rotated_layer[idx++];
        }
        
        return grid;
    }
};