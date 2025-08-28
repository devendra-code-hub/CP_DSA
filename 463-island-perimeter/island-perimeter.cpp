class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
          int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    
                    // Check top
                    if (i > 0 && grid[i-1][j] == 1) perimeter -= 2;

                    // Check left
                    if (j > 0 && grid[i][j-1] == 1) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};