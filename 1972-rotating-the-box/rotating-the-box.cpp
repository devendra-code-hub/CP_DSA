class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply gravity to each row (slide stones to the right)
        for (int i = 0; i < m; i++) {
            int lowestAvailableSlot = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    // Move stone to the lowest available slot
                    boxGrid[i][j] = '.';
                    boxGrid[i][lowestAvailableSlot] = '#';
                    lowestAvailableSlot--;
                } else if (boxGrid[i][j] == '*') {
                    // Obstacle resets the "bottom" for stones above it
                    lowestAvailableSlot = j - 1;
                }
            }
        }

        // Step 2: Rotate the box 90 degrees clockwise
        // New dimensions: n rows, m columns
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return rotatedBox;
    }
};