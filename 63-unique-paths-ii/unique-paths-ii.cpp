class Solution {
public:
int f(int i, int j, int m, int n,vector<vector<int>>&ch, vector<vector<int>>&dp){
    if(i==m-1 && j==n-1) return 1;
    if(i >= m || j>=n) return 0;
    if(ch[i][j]==1) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int d= f(i+1, j, m, n,ch, dp);
    int r= f(i, j+1, m, n, ch, dp);

    return dp[i][j]=d+r;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
         if(m==1 && n==1) return 1;
        vector<vector<int>>dp(m, vector<int>(n,-1));
         return f(0,0,m,n,obstacleGrid,dp);
    }
};