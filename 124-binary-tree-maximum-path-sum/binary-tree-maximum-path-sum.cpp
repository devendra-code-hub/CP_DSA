/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
       int findMax(TreeNode* root,int &maxi){
          if(root == NULL) return 0;

          int leftsum = max(0,findMax(root->left, maxi));
          int rightsum = max(0,findMax(root->right, maxi));
          maxi = max(maxi,leftsum + rightsum + root->val );

          return max(leftsum, rightsum) + root->val;
    }
public:
 
    int maxPathSum(TreeNode* root) {
          
         int maxi = INT_MIN;
         findMax(root,maxi);

         return maxi;
    }
  
};