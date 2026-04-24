class Solution {
    private:
     void dfs(int i,int j, int m, int n, int delr[],int delc[], vector<vector<int>>&vis,vector<vector<int>>&image, int ch, int color){
        vis[i][j] = 1;
        image[i][j] = color;
        for(int it=0; it<4; it++){
            int nr= i+delr[it];
            int nc= j+delc[it];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && image[nr][nc] == ch){
                dfs(nr,nc,m,n,delr,delc,vis,image,ch,color);
            }
        }
     }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int m = image.size(); 
       int n = image[0].size(); 
       vector<vector<int>>vis(m,vector<int>(n,0));
       int delr[]={-1,0,1,0};
       int delc[]={0,1,0,-1};
       int ch = image[sr][sc];

        
       dfs(sr,sc,m,n,delr,delc,vis,image,ch,color);

       return image;
        
    }
};