class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
        vector<vector<int>>c=matrix;
        for(int j=n-1; j>=0; j--){
            for(int i=0; i<n; i++){
                c[i][n-j-1]=matrix[j][i];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j]=c[i][j];
            }
        }


     
    }
};