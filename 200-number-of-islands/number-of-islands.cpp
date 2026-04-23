class Solution {
    private:
     void dfs(int i, int j,int m, int n, vector<vector<int>>&vis, vector<vector<char>>&grid ){
        vis[i][j] =1;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int it=0; it<4; it++){
            int nr=i+delr[it];
            int nc=j+delc[it];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,m,n,vis,grid);
            }
        }
     }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,m,n,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};