class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int fresh=0,time=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2)
                q.push({{i,j},0});
               else if(grid[i][j] == 1) fresh++;
                
            }
        }
        while(!q.empty()){
          pair<pair<int,int>,int> p = q.front();
          q.pop();
            int x=p.first.first;
            int y=p.first.second;
            int t = p.second;
            time=max(time,t);

            for(int i=0; i<4; i++){
                int nr=x+delr[i];
                int nc=y+delc[i];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        
        return fresh==0? time:-1;

    }
};