class Solution {
public:

   bool check(int r,int c, vector<string>&v,int n){
      // check up rows
      for(int i=r; i>=0; i--){
        if(v[i][c] == 'Q') return false;
      }
      // left upper diagonals
      for(int i=r,j=c; i>=0&&j>=0; i--,j--){
        if(v[i][j] == 'Q') return false;
      }
      // right upper diagonals

      for(int i=r,j=c; i>=0&& j<=n; i--,j++){
        if(v[i][j] == 'Q') return false;
      }
     return true;
   }

  void helper(int r,vector<string>&v,vector<vector<string>>&ans,int n){
    if(r==n){
        ans.push_back(v);
        return ;
    }
    for(int i=0; i<n; ++i){
        if(check(r,i,v,n) == false) continue;

        v[r][i]='Q';
        helper(r+1,v,ans,n);
        v[r][i]='.';
    }


  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string temp(n,'.');
        vector<string>v(n,temp);
        helper(0,v,ans,n);

        return ans;
    }
};