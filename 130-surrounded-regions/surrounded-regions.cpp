class Solution {
public:
   void dfs(int i, int j, int n, int m, vector<vector<int>>&vis, vector<vector<char>>&board, int delrow[], int delcol[]){
        vis[i][j] = 1;

        for(int r=0; r<4; r++){
            int nrow=i+delrow[r];
            int ncol=j+delcol[r];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
                dfs(nrow,ncol,n,m,vis,board,delrow,delcol);

        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[] ={-1,0,1,0};
        int delcol[] ={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<m; i++)  if(!vis[0][i] && board[0][i] == 'O') dfs(0,i,n,m,vis,board, delrow,delcol);
        for(int i=0; i<m; i++)  if(!vis[n-1][i] && board[n-1][i] == 'O') dfs(n-1,i,n,m,vis,board,delrow,delcol);
        for(int i=0; i<n; i++)  if(!vis[i][0] && board[i][0] == 'O') dfs(i,0,n,m,vis,board, delrow,delcol);
        for(int i=0; i<n; i++)  if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i,m-1,n,m,vis,board, delrow,delcol);

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
         
    }
};