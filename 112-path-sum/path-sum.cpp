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
   
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
          if(root == NULL) return 0;

          int subSum = targetSum-root->val;
          if(subSum == 0 && root->left == NULL && root->right == NULL) return 1;
          bool left = 0,right = 0;
          if(root->left){
           left= hasPathSum(root->left, subSum);
          }
          if(root->right){
           right = hasPathSum(root->right, subSum);
          }

          return left || right;
    }
};