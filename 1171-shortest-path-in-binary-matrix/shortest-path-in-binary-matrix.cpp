class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        int dr[]={-1,0,1,0,-1,-1,1,1};
        int dc[]={0,1,0,-1,-1,1,1,-1};
        dist[0][0]=1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int d=p.first;
            int r=p.second.first;
            int c=p.second.second;
            for(int i=0; i<8; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
     if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0 && (d+1)<dist[nr][nc]){
                    dist[nr][nc]=1+d;
                    q.push({d+1,{nr,nc}});
                }
                if(nr==n-1 && nc==n-1) return d+1;
            }
        }

        return -1;
    }
};