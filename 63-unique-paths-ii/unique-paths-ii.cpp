class Solution {
    private:
    int f(int i, int j, vector<vector<int>>&dp, int m, int n, vector<vector<int>>&obstacleGrid){
        if(i>=m || j>=n) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
         if(i==m-1 && j==n-1) return 1;
         if(dp[i][j] != -1) return dp[i][j];
         int d=f(i+1,j,dp,m,n, obstacleGrid);
         int r=f(i,j+1,dp,m,n, obstacleGrid);
         return dp[i][j] = d+r;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,-1));
         return f(0,0,dp,m,n,obstacleGrid);
    }
};