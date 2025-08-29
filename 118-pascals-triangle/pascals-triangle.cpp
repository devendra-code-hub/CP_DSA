class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;

    // Iterate through every line and 
    // print integer(s) in it
    for (int row = 0; row < numRows; row++) {
      
        // Every line has number of integers 
        // equal to line number
      	vector<int>arr;
        for (int i = 0; i <= row; i++) {
          
        // First and last values in every row are 1
        if (row == i || i == 0)
            arr.push_back(1);
          
        // Other values are sum of values just 
        // above and left of above
        else
            arr.push_back(mat[row - 1][i - 1] + 
                            mat[row - 1][i]);
        }
        mat.push_back(arr);
    }
  return mat;
        
    }
};