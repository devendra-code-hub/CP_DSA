class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            int low=0,high = m-1;
            while(low<=high){
            int mid = low + (high-low)/2; 
            int check = matrix[i][mid];
            if(check == target) return true;
            else if(check > target) high = mid-1;
            else low = mid+1;
            }
        }

        return false;
    }
};