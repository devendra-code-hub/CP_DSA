class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if( ( matrix[0][0] > target) ) {
           return false;
        }
        int check_row =0;
        for(int i=0; i<n; i++){
             if(matrix[i][0] == target ) return true;
             else if(matrix[i][0] > target){ check_row =i-1;break;}
        }
        for(int i=0; i<m; i++){
            if(matrix[check_row][i] == target) return true;
        }
        if(check_row == 0){
            for(int i=0; i<m; i++){
                if(matrix[n-1][i] == target) return true;
            }
        }

        return false;
    }
};