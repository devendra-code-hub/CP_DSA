class Solution {
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int helper(int r,int c, int cnt,vector<vector<int>>& grid, vector<vector<bool>>&vis ){
        int n=grid.size(),m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==-1 || vis[r][c]==true){
            return 0;
        }
        if(grid[r][c]==2){
            return (cnt==-1);
        }
        vis[r][c]=true;
        int ans=0;
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            ans+=helper(nr,nc,cnt-1,grid,vis);
        }
        vis[r][c]=false;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //helps me to store the number of empty squares;
        int cnt=0;
        int r,c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    r=i,c=j;
                }
                if(grid[i][j]==0){
                    cnt++;
                }
            }
        }
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int ans = helper(r,c,cnt,grid,vis);
        return ans;
    }
};
