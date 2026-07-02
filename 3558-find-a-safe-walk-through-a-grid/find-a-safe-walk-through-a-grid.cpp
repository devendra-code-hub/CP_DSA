class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
         int n=grid[0].size(),m=grid.size();
         vector<vector<int>>mn_damage(m,vector<int>(n,1e9));
         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
         mn_damage[0][0]=grid[0][0];
         pq.push({grid[0][0],0,0});
         int dr[]={-1,0,1,0};
         int dc[]={0,1,0,-1};
         while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int c_d=curr[0];
            int r=curr[1];
            int c=curr[2];
            if(r==m-1 && c==n-1) return health-c_d >0;
            if(c_d > mn_damage[r][c]) continue;
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int n_d=c_d+grid[nr][nc];
                    if(n_d<mn_damage[nr][nc]){
                        mn_damage[nr][nc]=n_d;
                        pq.push({n_d,nr,nc});
                    }
                }
            }
         }
 return false;
    }
};