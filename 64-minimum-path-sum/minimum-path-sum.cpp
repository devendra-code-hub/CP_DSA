class Solution {
public:
    int f(int i, int j, int n, int m,vector<vector<int>>&dp,vector<vector<int>>& grid ){
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int d=f(i+1,j,n,m,dp,grid);
        int r=f(i,j+1,n,m,dp,grid);
        return dp[i][j] = min(d,r) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
         
         return f(0,0,n,m,dp, grid);
    }
};